#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,t,u,s,cnt = 0;
	int a[n];
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> t;
		a[i] = t;
	}
	cout << a[n];
	return 0;
}
