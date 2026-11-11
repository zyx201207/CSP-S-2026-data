#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
char st;
const int N=550,K=5e5+10;
int C,n,m,d,q;
int w[K];
//vector<int> a[N],t[N];

int k[N];

int cnt,hd[K*4],nxt[K*4],to[K*4],f[K*4];

void add(int x,int y,int z)
{
	++cnt;
	nxt[cnt]=hd[x];
	hd[x]=cnt;
	to[cnt]=y;
	f[cnt]=z;
	return;
}

struct qst{
	int x,y,id;
}qs[K];

bool cmp(qst x,qst y)
{
	return x.x<y.x;
}

#define PI pair<ll,int>
#define fi first
#define se second

priority_queue<PI,vector<PI>,greater<PI>> p;
ll dis[K*2+N*2];
const ll INF=1e18;

void Dij(int s)
{
	fill(dis+1,dis+m*2+n+1,INF);
	dis[s]=0ll;
	p.push({0ll,s});
	while(!p.empty())
	{
		PI x=p.top();
		p.pop();
		if(dis[x.se]!=x.fi) continue;
		for(int i=hd[x.se];i;i=nxt[i])
		{
			int v=to[i];
			if(v<s) continue;
			//printf("%lld %d %d ",dis[x.se],dis[v],f[i]);
			if(dis[v]>dis[x.se]+(ll)f[i])
			{
				//printf("%d ",v);
				dis[v]=dis[x.se]+(ll)f[i];
				p.push({dis[v],v});
			}
		}
	}
}

ll ans[K];
char ed;
int main()
{
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	
//	freopen("subway4.in","r",stdin);freopen("subway.out","w",stdout);
	
//	system("fc subway.out subway4.ans");
//	return 0;
	
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&w[i]);
		
		add(i,m+i,w[i]);
		add(m+i,i,w[i]);
		
	}
	
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];++j)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			
			add(m+x,m*2+i,y);
			add(m*2+i,m+x,y);
			
			//a[i].pb(x),t[i].pb(y);
		}
	}
	
	for(int i=1;i<=q;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		qs[i]={x,y,i};
	}
	
	sort(qs+1,qs+q+1,cmp);
	
	for(int i=1;i<=q;++i)
	{
		if(qs[i].x!=qs[i-1].x)
		{
			Dij(qs[i].x);
		}
		ans[qs[i].id]=dis[qs[i].y];
	}
	
	for(int i=1;i<=q;++i)
	{
		printf("%lld\n",ans[i]);
	}
	
	return 0;
}
