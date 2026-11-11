#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[1005][1005];
bool vis[100005];
long long c,n,m,d,q;
long long ans=1e9;
void dfs(long long x,long long t,long long y)
{
	vis[x]=1;
	if(x==y){
		ans=min(ans,t);
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(vis[i]==0&&b[x][i])
		{
			dfs(i,t+b[x][i],y);
			vis[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		long long s;
		cin>>s;
		long long x1[10005],y1[10005];
		for(int i=1;i<=s;i++)
		{
			long long x,y;
			cin>>x>>y;
			x1[i]=x;
			y1[i]=y;
		}
		for(int i=2;i<=s;i++)
		{
			b[x1[i-1]][x1[i]]=y1[i-1]+y1[i];
		    b[x1[i]][x1[i-1]]=y1[i-1]+y1[i];
		}		
	}
	
	while(q--)
	{
		ans=1e9;
		long long x,y;
		cin>>x>>y;
		long long t=a[x]+a[y];
		dfs(x,t,y);
		for(int i=1;i<=m;i++)
		{
			vis[i]=0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
