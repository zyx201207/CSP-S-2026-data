#include<bits/stdc++.h>
using namespace std;
int w[500005];
int a[505][500005],t[505][500005];
int dfs(int e,int s,int r)
{
	if(s==e)return w[s]+t[r][s];
	for(int i=1;i<=k[e];i++)
		ans=max(dfs(e,x,a[y][i])+w[y],ans);
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		for(int i=1;i<=k[y];i++)
			ans=max(dfs(y,x,a[y][i])+w[y],ans);
		cout<<ans<<"\n";
	}
	return 0;
}
