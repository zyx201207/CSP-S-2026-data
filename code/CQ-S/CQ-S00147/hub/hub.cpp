#include<bits/stdc++.h>
using namespace std;
int n,k,ans=1e9,dis[100000];
vector<int> g[1000005];
void dd(int x,int fa)
{
	for(auto y:g[x])
	{
		if(y==fa) continue;
		dis[y]=dis[x]+1;
		dd(y,x);
	}
}
void d2(int x,int fa)
{
	for(auto y:g[x])
	{
		if(y==fa) continue;
		dis[y]=dis[x]+1;
		d2(y,x);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					for(int k=1;k<=n;k++) dis[k]=0;
					dd(i,0);
					int s=0,A;
					for(int a=1;a<=n;a++) if(s<dis[a]) s=dis[a],A=a;
					dis[A]=0;
					d2(A,0);
					s=0;
					for(int a=1;a<=n;a++) s=max(s,dis[a]);
					ans=min(ans,s/2);
				}
			}
		}
		else if(k==1) ans=0;
		else ans=1;
		cout<<ans<<endl;
	}
	return 0;
}
