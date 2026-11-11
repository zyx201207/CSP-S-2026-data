#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
constexpr int N = 2e6 + 66;
int c, t, n, x[N], d, pre[N], suf[N];
bool vis[N];
int find_next(int val)
{
	int l = 1, r = n;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(x[mid] == val) return mid;
		else if(x[mid] > val) r = mid - 1;
		else l = mid + 1;
	}
	return r;
}
bool check(int l, int r)
{
	if(r - l + 1 <= 3) return false;
	int nw = l, cnt = 0;
	for(int i = l;i <= r;i ++) pre[i] = suf[i] = vis[i] = 0;
	vis[r] = 1;
	while(nw < r) 
	{
		int nxt = min(r, find_next(x[nw] + d));
		if(nxt == nw) return false;
		vis[nw] = 1;
		nw = nxt;
	}
	for(int i = l, lst = i;i <= r;i ++) 
	{
		if(vis[i]) lst = i;
		pre[i] = lst;
	}
	for(int i = r, lst = i;i >= l;i --) 
	{
		if(vis[i]) lst = i;
		suf[i] = lst;
	}
	for(int i = l;i <= r;i ++)
	{
		if(vis[i]) continue;
		if(x[i] - x[pre[i]] <= d && x[suf[suf[i]]] - x[i] <= d) cnt ++;
	}
	return cnt == 1;
}
signed main()
{
	freopen("migrate.in", "r", stdin);freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> d;ll ans = 0;
		for(int i = 1;i <= n;i ++) cin >> x[i];
		for(int i = 1;i <= n;i ++) 
			for(int j = i;j <= n;j ++) 
				ans += check(i, j);
		cout << ans << '\n';
	}
	return 0;
}
