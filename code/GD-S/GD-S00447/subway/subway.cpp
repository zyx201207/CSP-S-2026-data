#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y,a[500005];
long long v[500005],t[500005],tot,dis[500005],twf[500005][3];
bool vis[500005],b[505],yb[505];
long long hed[500005],to[2000005],nxt[2000005],w[2000005];
struct CHY
{
	int id;
	long long d;
	bool operator < (CHY a)const
	{
		return d>a.d;
	}
};
priority_queue<CHY> p;
vector<int> e[500005],en[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>v[i];
	if(c<=15||c>=24)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>a[j]>>t[j];
			}
			for(int j=1;j<=k;j++)
			{
				for(int g=1;g<=k;g++)
				{
					if(j==g)continue;
					to[++tot]=a[g];
					nxt[tot]=hed[a[j]];
					hed[a[j]]=tot;
					w[tot]=t[j]+t[g];
				}
			}
		}
		for(int ll=1;ll<=q;ll++)
		{
			cin>>x>>y;
			for(int i=1;i<=m;i++)
			{
				dis[i]=1e15+7;
				vis[i]=false;
			}
			dis[x]=0;
			p.push({x,0});
			while(!p.empty())
			{
				int s=p.top().id;
				p.pop();
				if(vis[s])continue;
				vis[s]=true;
				for(int j=hed[s];j;j=nxt[j])
				{
					if(dis[to[j]]>dis[s]+w[j])
					{
						dis[to[j]]=dis[s]+w[j];
						p.push({to[j],dis[to[j]]});
					}
				}
			}
			cout<<dis[y]+v[x]+v[y]<<"\n";
		}
	}
	else if(c<=19)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)b[j]=false;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>a[j]>>t[j];
				int zj=e[a[j]].size();
				for(int pp=0;pp<zj;pp++)
				{
					if(b[e[a[j]][pp]])continue;
					en[i].push_back(e[a[j]][pp]);
					en[e[a[j]][pp]].push_back(i);
				}
				e[a[j]].push_back(i);
			}
		}
		for(int ll=1;ll<=q;ll++)
		{
			cin>>x>>y;
			long long ans=1e15+7;
			int zj=e[x].size();
			for(int zw=0;zw<zj;zw++)
			{
				p.push({e[x][zw],0});
				for(int i=1;i<=n;i++)
				{
					dis[i]=1e15+7;
					vis[i]=false;
				}
				dis[e[x][zw]]=0;
				while(!p.empty())
				{
					int s=p.top().id;
					p.pop();
					if(vis[s])continue;
					vis[s]=true;
					int jx=en[s].size();
					for(int j=0;j<jx;j++)
					{
						int tov=en[s][j];
						if(dis[tov]>dis[s]+2)
						{
							dis[tov]=dis[s]+2;
							p.push({tov,dis[tov]});
						}
					}
				}
				int lsy=e[y].size();
				for(int i=0;i<lsy;i++)
				{
					ans=min(ans,dis[e[y][i]]);
				}
			}
			cout<<(ans+2)*t[1]+v[x]+v[y]<<"\n";
		}
	}
	else if(c<=21)
	{
		
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>a[j]>>t[j];
				twf[a[j]][i]=t[j];
			}
		}
		long long cnt=1e15+7; 
		for(int i=1;i<=m;i++)
		{
			if(twf[i][1]&&twf[i][2])
			{
				cnt=min(cnt,twf[i][1]+twf[i][2]);
			}
		}
		for(int ll=1;ll<=q;ll++)
		{
			cin>>x>>y;
			if(n==1)
			{
				cout<<v[x]+v[y]+twf[x][1]+twf[y][1]<<"\n";
			}
			else
			{
				long long lsy=v[x]+v[y]+twf[x][1]+twf[y][1]+twf[y][2]+twf[x][2]+cnt;
				if(twf[x][1]&&twf[y][1])
				{
					lsy=min(lsy,v[x]+v[y]+twf[x][1]+twf[y][1]);
				}
				if(twf[x][2]&&twf[y][2])
				{
					lsy=min(lsy,v[x]+v[y]+twf[x][2]+twf[y][2]);
				}
				cout<<lsy<<"\n";
			}
		}
	}
	return 0;
}
