#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 100;

int a[maxn];
int n;
int b[maxn];
int m;
int ans = 0;
bool vis[maxn];

bool cmp (int x ,int y) {
	return x > y;
}

void dfs (int pos)
{
	if (pos > m)
	{
		int cnt = b[1];
		for (int i = 2; i <= m; i++) cnt &= b[i];
		ans = max(ans ,cnt);
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		vis[i] = true;
		b[pos] = a[i];
		dfs(pos + 1);
		vis[i] = false;
	}
}

signed main()
{
	freopen("and.in" ,"r" ,stdin);
	freopen("and.out" ,"w" ,stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(1);
	cout << ans << '\n';
	
	return 0;
}
