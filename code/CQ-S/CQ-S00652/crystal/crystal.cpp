#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N =  5e5 + 10;
long long  n, m;
int a[N];
void add()
{
	long long sum = 0;

	long long y = n / 2 +1;
	while(1)
	{
		if(a[y] == a[y + 1]) y++;
		else break;
	}
	int b = 0;
	b = y; 

	int  c = 1;
	while(m + 1)
	{
		if(a[b] == a[b - 1]) 
		{
			b--;
			c++;
		}
		else
		{
			a[b - 1]++;
			m--;
		}
		
	}
	cout << c;
}


void sort()
{
	int op = 0;
	for(int i = 1; i <= n; i++)
	{
		op = 0;
		for(int j = 1; j <= n - i; j++)
		{
			if(a[j] > a[j + 1]) 
			{
				swap(a[j],a[j + 1]);
				op++;
			}
		}
		if(op == 0) break;
	}
}

int main()
 {
 	freopen("crystal.in", "r",stdin);
 	freopen("crystal.out", "w",stdout);
 	cin >> n >> m;
 	for(int i = 1; i<=n; i++)
 	{
 		int x;
 		cin >> x;
 		a[i] = x;
	}
	sort();
	add();
 	return 0;
 }
