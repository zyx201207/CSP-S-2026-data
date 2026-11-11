#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Abs(x,y) (x>y?x-y:y-x)
int c,t;
int n,d;
int ans=0,f=0;
bool vis[3005];
int x[2000005];
int dis[3005][3005];
void dfs(int u,int s,int e,int st)
{
	if(f>2)return ;
	if(st>dis[s][e])return ;
	if(u==e)
	{
//		cout<<e<<" "<<s<<" "<<st<<"\n";
		if(st==dis[s][e])f++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(Abs(x[u],x[i])<=d && u!=i && vis[i]==0)
		{
			vis[i]=1;
			dfs(i,s,e,st+1);vis[i]=0;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			int k=0;ans=0;
			for(int i=1;i<=n;i++)
				if(Abs(x[1],x[i])>d){k=i-1;break;}
			n-=k;while(n){ans+=n;n-=k-1;}
			cout<<ans<<"\n";
		}return 0;
	}
	while(t--)
	{
		cin>>n>>d;memset(dis,0x3f3f,sizeof dis);
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(Abs(x[i],x[j])<=d && i!=j)dis[i][j]=1;
		for(int i=1;i<=n;i++)
			for(int k=1;k<=n;k++)
			{
				if(dis[i][k]==0x3f3f3f3f3f3f3f3f || i==k)continue;
				for(int j=1;j<=n;j++)
				{
					if(dis[k][j]==0x3f3f3f3f3f3f3f3f || i==j || j==k)continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
			{memset(vis,0,sizeof vis);f=0;
				dfs(i,i,j,0);if(f==2)ans++;/*cout<<dis[i][j]<<" ";*/}
				/*cout<<"\n";*/}
		cout<<ans<<"\n";
	}
	return 0;
}
