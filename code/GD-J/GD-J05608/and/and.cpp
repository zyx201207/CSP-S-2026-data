#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[100000];
string b[100000];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "W", stdout);
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	int i;
	while(i>1)
	{
		int i=a[1];
		b[1] += i%2;
		i/=2;
	}
	cout << b[1];
	return 0;
} 
