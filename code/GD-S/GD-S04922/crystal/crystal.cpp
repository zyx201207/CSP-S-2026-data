#include<bits/stdc++.h>
using namespace std;
const int N = 1e8 + 10;
int a[N];
int n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[n];
	}
	int mid,x;
	for (int i = 1;i <= m;i++)
	{
		cin >> x;
		mid = a[n/2+1];
		if (i == mid)
			x++;
	}
	cout << x;
	return 0;
}
