#include <bits/stdc++.h>
using namespace std;

int n,m,a[100020];
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	long long b = pow(2,30)-1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1; i <= m; i++)
	{
		b = b&a[i];
	}
	cout << b;
	return 0;
 } 
