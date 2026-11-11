#include <bits/stdc++.h>
using namespace std;
const int N=4005,inf=1e9;
int c,t,n,m,la[N],ra[N],op,rt,d[N],d2[N],f[N];
int h[N],cnt;
struct node{int next,to;}a[N<<1];
void add(int x,int y){a[++cnt]={h[x],y},h[x]=cnt;}
void dfs(int x,int y)
{
	int mx=0,mx2=0;f[x]=1;
	for(int k=h[x];k;k=a[k].next)
	{
		int i=a[k].to;
		if(i==y) continue;dfs(i,x);
		if(d[i]+1>mx2){mx2=d[i]+1;if(mx2>mx) swap(mx,mx2);}
		if(d[i]+1>rt) f[x]+=f[i];
	}
	d[x]=mx,d2[x]=mx2;
}
void dfs2(int x,int y,int dd)
{
	if(dd+1>rt) return;op=min(op,f[x]);
	for(int k=h[x];k;k=a[k].next)
	{
		int i=a[k].to;if(i==y) continue;
		if(d[i]+1>d2[x]) dfs2(i,x,max(dd+1,d2[x]));
	}
}
int check(int w)
{
	rt=w;
	for(int x,y,i=1;i<n;i++)
	{
		x=la[i],y=ra[i];op=inf;int as=0;
		dfs(x,y),dfs2(x,y,-1);
		as+=op,op=inf;if(as>m) continue;
		dfs(y,x),dfs2(y,x,-1);
		as+=op;if(as<=m) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) h[i]=0;cnt=0;
		for(int x,y,i=1;i<n;i++) cin>>x>>y,la[i]=x,ra[i]=y,add(x,y),add(y,x);
		int l=0,r=n,mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(!check(mid)) l=mid+1;
			else r=mid-1;
		}
		cout<<l<<'\n';
	}
	return 0;
}
