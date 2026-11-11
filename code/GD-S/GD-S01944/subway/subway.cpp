#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rig register int
#define cit const int&
#define void inline void
#define N 5000005
int c,n,m,d,q,cnt,w[N],h[N],f[N],id[N];
struct node{ int to,nxt,val; }e[N];
void edge(cit u,cit v,cit val) { e[++cnt]={v,h[u],val}; h[u]=cnt; }
void adeg(cit u,cit v,cit val) { edge(u,v,val); edge(v,u,val); }
void up(cit i)
{
	if(i==1) return;
	if(f[id[i]]<f[id[i/2]]) swap(id[i],id[i/2]),up(i/2);
}
void add(cit i) { id[++cnt]=i; up(cnt); }
void down(cit i)
{
	rig j=i*2;
	if(j>=cnt) return;
	if(j+1<=cnt&&f[id[j+1]]<f[id[j]]) j=j+1;
	if(f[id[j]]<f[id[i]]) swap(id[i],id[j]),down(j);
}
void erase() { id[1]=id[cnt--]; down(1); }
main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(rig i=1;i<=m;i++) cin>>w[i];
	for(rig i=1,k,tot=m;i<=n;i++)
	{
		cin>>k;
		for(rig l=-1,r,val;k;k--)
		{
			cin>>r>>val;
			adeg(r,++tot,val);
			if(~l) adeg(l,tot,0); l=tot;
		}
	}
	for(rig x,y;q;q--)
	{
		cin>>x>>y;
		memset(f,127,sizeof f); f[x]=cnt=0; add(x);
		while(cnt)
		{
			int u=id[1]; erase();
			for(int i=h[u];i;i=e[i].nxt)
			{
				int v=e[i].to,val=e[i].val;
				if(f[u]+val<f[v]) f[v]=f[u]+val,add(v);
			}
		}
		cout<<f[y]+w[x]+w[y]<<'\n';
	}
}
