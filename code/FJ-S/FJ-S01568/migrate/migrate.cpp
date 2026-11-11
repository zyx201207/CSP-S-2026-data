#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=2e6+10,INF=1e18;
int c,T,n,d,a[N],f[N],g[N];
set<PII> s;
struct node
{
	int l,r,minv,minsum;
}tr[N<<2];
void pushup(int u)
{
	if(tr[u<<1].minv<tr[u<<1|1].minv)
	{
		tr[u].minv=tr[u<<1].minv;
		tr[u].minsum=tr[u<<1].minsum;
	}
	else if(tr[u<<1].minv>tr[u<<1|1].minv)
	{
		tr[u].minv=tr[u<<1|1].minv;
		tr[u].minsum=tr[u<<1|1].minsum; 
	}
	else
	{
		tr[u].minv=tr[u<<1].minv;
		tr[u].minsum=tr[u<<1].minsum+tr[u<<1|1].minsum;
	}
}
void build(int u,int l,int r)
{
	if(l==r)tr[u]={l,l,INF,1};
	else
	{
		tr[u]={l,r,INF,1};
		int mid=(l+r)>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		pushup(u);
	}
}
void modify(int u,int x,int k1,int k2)
{
	if(tr[u].l==x&&tr[u].r==x)tr[u].minv=k1,tr[u].minsum=k2;
	else
	{
		int mid=(tr[u].l+tr[u].r)>>1;
		if(x<=mid)modify(u<<1,x,k1,k2);
		if(x>mid)modify(u<<1|1,x,k1,k2);
		pushup(u);
	}
}
PII query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r)return {tr[u].minv,tr[u].minsum};
	int mid=(tr[u].l+tr[u].r)>>1;
	PII p1={INF,0},p2={INF,0};
	if(l<=mid)p1=query(u<<1,l,r);
	if(r>mid)p2=query(u<<1|1,l,r);
	if(p1.first<p2.first)return p1;
	if(p2.first<p1.first)return p2;
	return {p1.first,p1.second+p2.second};
}
void solve()
{
	int m=a[2]-a[1];
	int x=d/m;
	if(x==0||x==1)cout<<"0\n";
	else cout<<max(0ll,n-(2*x-1))<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		s.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s.insert({a[i],i}); 
		}
		if(c==11||c==12)
		{
			solve();
			continue;
		}
		build(1,1,n);
		int res=0;
		for(int u=1;u<=n;u++)
		{
			for(int i=u+1;i<=n;i++)
			{
				f[i]=INF;
				g[i]=0;
			}
			f[u]=0;
			g[u]=1;
			modify(1,u,0,1);
			for(int i=u+1;i<=n;i++)
			{
				auto it=s.lower_bound({a[i]-d,0});
				int x=max(u,it->second);
				auto p=query(1,x,i-1);
				f[i]=p.first+1;
				g[i]=p.second;
				modify(1,i,f[i],g[i]);
			}
			for(int i=u;i<=n;i++)
				if(g[i]==2)res++;
		}
		cout<<res<<endl;
	}
	return 0;
}
