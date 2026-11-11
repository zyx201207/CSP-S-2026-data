//hub.cpp,3s,1024MiB
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[1000005];
int c[15],dis[15][15];
int ro(int x)
{
	return c[x]=(x==c[x]?x:ro(c[x]));
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cc,_;
	cin>>cc>>_;
	if(cc>3)
		return 0;
	while(_--)
	{
		int n,k,Ans=LLONG_MAX;
		cin>>n>>k;
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			dis[i][i]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			dis[u][v]=1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		for(int mask=0;mask<(1<<n);mask++)
		{
			for(int i=1;i<=n;i++)
				c[i]=i;
			for(int i=1;i<=n;i++)
				if(mask&(1<<(i-1)))
					for(int j=i+1;j<=n;j++)
						if(mask&(1<<(j-1)))
							if(dis[i][j]==1)
								c[ro(i)]=ro(j);
			int s=0;
			for(int i=1;i<=n;i++)
				s+=(ro(i)==i);
			if(s>2)
				continue;
			int dmax=0;
			for(int i=1;i<=n;i++)
			{
				int d=LLONG_MAX;
				for(int j=1;j<=n;j++)
					if(mask&(1<<(j-1)))
						d=min(d,dis[i][j]);
				dmax=max(d,dmax);
			}
			Ans=min(Ans,dmax);
		}
		cout<<Ans<<'\n';
	}
}
