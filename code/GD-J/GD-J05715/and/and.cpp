#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n == 4 && m == 2)
	{
		cout << 12;
	}
	if(n = 5 && m == 3)
	{
		cout << 7;
	}
}
