#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500005];
int p[300005];
int c[300005];
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		p[a[i]] = i;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			if(p[a[j]] != j)
				j = p[a[j]];
			c[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++)
		cout << c[i] << " ";
	return 0;
}
