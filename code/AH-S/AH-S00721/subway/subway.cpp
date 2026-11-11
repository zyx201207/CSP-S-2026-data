#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[50005],a[50005],t[1005][505],id[105],le,id1[105],ll;
bool f[1005][1005][505];
int x,y,k,ans,minn;
void dfs(int step,int cnt)
{
	if(step==y)
	{
		minn=min(minn,cnt);
		return;
	}
	if(cnt>minn)
		return;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(f[step][j][i])
			{
				f[step][j][i]=0;
				f[j][step][i]=0;
				dfs(j,cnt+t[i][j]+t[i][step]);
				f[step][j][i]=1;
				f[j][step][i]=1;
			}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t[i][a[j]];
		for(int j=1;j<=k;j++)
			for(int l=j+1;l<=k;l++)
			{
				f[a[j]][a[l]][i]=1;
				f[a[l]][a[j]][i]=1;
			}
	}
	while(q--)
	{
		minn=INT_MAX;
		cin>>x>>y;
		ans=0;
		ans+=w[x]+w[y];
		dfs(x,0);
		ans+=minn;
		cout<<ans<<endl;
	}
	return 0;
}
