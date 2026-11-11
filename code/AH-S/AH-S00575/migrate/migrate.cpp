#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
#define ll long long
ll x[N], d;
int t, n;
int len[N];
bool vis[N];
vector<int>st[N];
int c;
struct node{
	int val, num;
};
int Max(int i, int j)
{
	int sum = 0;
	int now = i;
	while(x[now] < x[j])
	{
		now = st[now][len[now] - 1];
		++sum;
	}
	return sum;
}
bool deal(int i, int j)
{
	int sum = 0;
	queue<node>q;
	node g;
	g.val = i, g.num = 0;
	q.push(g);
	ll kl = Max(i, j);
	if (kl >= (j - i - 1)) return false;
	for(int z = i; z <= j; ++z) vis[z] = 0;
	while(!q.empty())
	{
		node f = q.front();q.pop();
		if (f.num > kl) break;
		if (vis[f.val]) continue;
		vis[f.val] = 1;
		for (int z = len[f.val] - 1; z >= 0; --z)
		{
			if (st[f.val][z] > j) continue;
			if (st[f.val][z] == j)
			{
				++sum;
			}else{g.val = st[f.val][z], g.num = f.num + 1, q.push(g);}
		}
		if (sum > 2) return false;
	}
	return sum == 2;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (x[j] - x[i] <= d)
				{
					st[i].push_back(j);
					len[i]++;
				}
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				ans += deal(i, j);
			}
		}
		cout << ans << "\n";
		for (int i = 1; i <= n; ++i)
		{
			if (len[i] > 0)
				while(!st[i].empty()) st[i].pop_back();
			len[i] = 0;
		}
	}
	return 0;
}
