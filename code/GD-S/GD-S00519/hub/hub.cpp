#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000010],k,first[1000010],ct,x,y,bj[1000010],dis[1000010];
struct node
{
	int to,next,w;
}tr[2000010];
void add(int x,int y)
{
	tr[++ct].to=y;
	tr[ct].next=first[x];
	first[x]=ct;
}
void dfs(int u)
{
	for(int i=first[u];i;i=tr[i].next)
	{
		int v=tr[i].to;
		if(bj[v])continue;
		bj[v]=1,dfs(v);
	}
}
void dft(int u,int fa)
{
	for(int i=first[u];i;i=tr[i].next)
	{
		int v=tr[i].to;
		if(v==fa)continue;
		dis[v]=dis[u]+1;
		dft(v,u);
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	int t,C;
	cin>>C>>t;
	while(t--)
	{
		int ans=1e9;
		cin>>n>>k;
		ct=0;
		memset(first,0,sizeof(first));
		for(int i=1;i<n;i++)cin>>x>>y,add(x,y),add(y,x);
		for(int i=0;i<(1<<n);i++)
		{
			int gd=0,pj=i,ltk=0;
			while(pj)gd+=pj%2,pj/=2;
			memset(bj,0,sizeof(bj));
			if(gd!=k)continue;
			for(int j=1;j<=n;j++)
			{
				if((i&(1<<(j-1)))==0)continue;
				if(!bj[j])bj[j]=1,dfs(j),ltk++;
			}
			if(ltk>2)continue;
			int ma=0;
			for(int j=1;j<=n;j++)
			{
				if((i&(1<<(j-1))))continue;
				dis[j]=0;
				dft(j,j);
				int mi=1e9;
				for(int p=1;p<=n;p++)if(i&(1<<(p-1)))mi=min(mi,dis[p]);
				ma=max(ma,mi);
			}
			ans=min(ans,ma);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
