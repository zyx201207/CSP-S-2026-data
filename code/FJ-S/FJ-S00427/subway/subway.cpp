#include<bits/stdc++.h>
using namespace std;
typedef long long ljl;
#define pii pair<ljl,int>
#define mkp make_pair
void Rd(int &x);
const int N=505,M=5e5+5,NDS=M*2+N*25+5,QNUM=1e5+5;
const ljl inf=1e18;
int c,n,m,d,q,cnt_e,ehead[NDS],tot;
//2i-1,2i号点表示第i个地铁站的站口/站厅 
ljl dis[NDS],ans[QNUM];
bool vis[NDS];
priority_queue<pii,vector<pii >,greater<pii > > hp;
struct Q{
	int u,v,p;
	bool operator < (const Q &a)const{
		return u<a.u;
	}
}qry[QNUM];
struct E{
	int to,pre;ljl w;
}e[M*2];
void adde(int from,int to,ljl w)
{
	e[++cnt_e].to=to;
	e[cnt_e].w=w;e[cnt_e].pre=ehead[from];
	ehead[from]=cnt_e;
	return;
}
void dijk(int s)
{
	for(int i=1;i<=tot;++i)dis[i]=inf,vis[i]=0;
	dis[s]=0;hp.push(mkp(0,s));
	while(!hp.empty())
	{
		int u=hp.top().second;hp.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=ehead[u];i;i=e[i].pre)
		{
			int v=e[i].to;ljl w=e[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!vis[v])hp.push(mkp(dis[v],v));
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Rd(c);Rd(n);Rd(m);Rd(d);Rd(q);
	for(int i=1,w;i<=m;++i)
	{
		Rd(w);adde(2*i-1,2*i,1ll*w);
		adde(2*i,2*i-1,1ll*w);
	}tot=2*m;
	for(int i=1,k,a,t;i<=n;++i)
	{
		Rd(k);int tt=0;
		while(k--)
		{
			Rd(a);Rd(t);++tot;
			if(!tt)tt=tot;
			adde(tot,2*a,1ll*t);adde(2*a,tot,1ll*t);
			if(tot!=tt){adde(tt,tot,0);adde(tot,tt,0);}
		}
	}
	for(int i=1;i<=q;++i)
	{
		Rd(qry[i].u);Rd(qry[i].v);qry[i].p=i;
		qry[i].u=qry[i].u*2-1;qry[i].v=qry[i].v*2-1;
	}
	sort(qry+1,qry+q+1);
	for(int i=1;i<=q;++i)
	{
		int u=qry[i].u;
		dijk(u);int j=i;
		for(;j<=q&&qry[j].u==u;++j)
			ans[qry[j].p]=dis[qry[j].v];
		i=j-1;
	}
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
	return 0;
}
void Rd(int &x)
{
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return;
}
