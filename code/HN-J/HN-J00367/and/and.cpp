#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int a[N],n,m,ans;
int g[N];
void dfs(int x,int p)
{
	if(x==m)
	{
		int cnt=g[1];
		for(int i=2;i<=m;i++) cnt&=g[i];
		ans=max(cnt,ans);
		return;
	}
	for(int i=p;i<=n;i++)
	{
		g[x+1]=a[i];
		dfs(x+1,i+1);
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
	dfs(0,1);
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

12

5 3
31 3 1 15 7

7
*/
