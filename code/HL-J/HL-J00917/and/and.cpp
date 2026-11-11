#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans = LLONG_MIN,a[200005],p[200005];
bool vis[200005];
inline void dfs(int u,int l)
{
	if(u == m)
	{
		int cnt = p[1];
		for(int i=2;i<=m;i++) cnt &= p[i];
		ans = max(ans,cnt);
		return;
	}
	for(int i=l+1;i<=n;i++)
	{
		vis[i] = 1;
		p[u+1] = a[i];
		dfs(u+1,i);
		vis[i] = 0;
	}
	return;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m == n)
	{
		int cnt = a[1];
		for(int i=2;i<=n;i++) cnt &= a[i];
		cout<<cnt<<"\n";
		return 0;
	}
	dfs(0,0);
	cout<<ans<<"\n";
	return 0;
}