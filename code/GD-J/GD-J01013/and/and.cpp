#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ma=-1e9;
bool vis[200005];
void dfs(int x,int dep)
{
	if(dep==m)
	{
		ma=max(ma,x);
		return;
	}
	for(int i=1;i<=n;i++) if(!vis[i]) vis[i]=1,dfs(a[i]&x,dep+1);
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
    	vis[i]=1;
    	dfs(a[i],1);
    	memset(vis,0,sizeof(vis));
	}
	cout<<ma;
    return 0;
}

