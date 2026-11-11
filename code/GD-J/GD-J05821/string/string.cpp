#include <bits/stdc++.h>
using namespace std;
long long a[150];
int main()
{
	int n,x,cnt=0;
	cin >> n;
	char s;
	string cc;
	for (int i=0;i<n;i++)
	{
		cin >> x;
		cin >> s;
		a[s]+=x;
	}
	cout << a[97];
	return 0;
} 
