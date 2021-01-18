#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

template <class T>
class linkList {

private:
	template <class T>
	struct node {

			T Data;
			node *next;
	};

	node<T>* head;

public:
	linkList() {
		head = NULL;
	}

	void insert(T item) {
		node<T>* t = head;
		node<T>* p;

		if (head == NULL)
		{
			head = new node<T>;
			head->Data = item;
			head->next = NULL;
		}
		else
		{
			while (t->next != NULL)
			{
				t = t->next;
			}
			p = new node <T>;
			t->next = p;
			p->Data = item;
			p->next = NULL;
		}


	}
	void print() {
		node<T>* t = head;
		while (t != NULL)
		{
			cout << t->Data << "   ";
			t = t->next;
		}
		cout << endl;
	}

	T del(T item)
	{
		node <T>* p, * t;
		p = head;
		if (p->Data == item) // delete from the beginning
		{
			head = p->next;
			delete p;
			return 0;
		}
		t = p;
		while (p != NULL)
		{
			if (p->Data == item)
			{
				t->next = p->next;
				delete p;
				return 0;
			}
			t = p;
			p = p->next;
		}
	}

	void insertion(node* sorted, node* current)
	{
		node* curr;
		if (sorted->next == NULL || sorted->Data >= current->Data)
		{
			current->next = sorted;
			sorted = current;
		}
		else
		{
			curr = sorted;
			while (curr->next != NULL || curr->next->Data < sorted->Data)
			{
				curr = curr->next;
			}
			current->next = curr->next;
			curr->next = current;
		}
	}

	void insertionSort()
	{
		node<T> *current = NULL, *next = NULL, *sorted;
		sorted = NULL;
		current = head;
		while (current != NULL)
		{
			next = current->next;

			insertion(sorted, current);

			current = next;
		}
		head = sorted;
		
	}
	
};



void insertionSort(int arr[], int);
void printArray(int arr[], int n);

int main()
{
	srand((unsigned)time(0));
	int arre[30];
	for (int i = 0; i < 30; i++)
		arre[i] = rand() % 50;
	printArray(arre, size(arre));
	insertionSort(arre, size(arre));
	printArray(arre, size(arre));


	linkList<int> obj_one;
	obj_one.insert(55);
	obj_one.insert(44);
	obj_one.insert(3);
	obj_one.insert(6);
	obj_one.insert(1);
	obj_one.print();
	obj_one.insertionSort();
	obj_one.print();

	return 0;
}

void insertionSort(int arr[], int Size)
{
	int key, j;
	for (int i = 0; i < Size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key )
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
