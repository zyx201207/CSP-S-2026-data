#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a;
bool b[200005][55], vis[200005];
void add(ll k, ll j)
{
	ll t = 1 << 29;
	for(int i = 1; i <= 30; i++)
	{
		b[j][i] = (t & k);
		t >>= 1;
	}
}
ll query(ll k)
{
	ll t = 1 << 29, res = 0, sum;
	for(int i = 1; i <= 30; i++)
	{
		sum = 0;
		for(int j = 1; j <= n; j++)
		{
			if(!vis[j] && b[j][i])
			{
				sum++;
			}
		}
		if(sum >= m)
		{
			res += t;
			for(int j = 1; j <= n; j++)
			{
				if(!b[j][i])vis[j] = 1;
			}
		}
		t >>= 1;
	}
	return res;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a;
		add(a, i);
	}
	cout << query(m);
	return 0;
}

