#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int c,n,k,hd[N],cnt,f[N],b[N],ans,bz[N],len;
struct T{ int to,nxt;}e[2*N];
void add(int x,int y){ e[++cnt]={y,hd[x]};hd[x]=cnt;}
void dfss(int x,int fa,int y)
{
	if(y>f[x]) return ;
	f[x]=y;
	for(int i=hd[x];i;i=e[i].nxt)
	{ if(e[i].to!=fa) dfss(e[i].to,x,y+1);}
}
void clr(int x)
{
	bz[x]=1;
	for(int i=hd[x];i;i=e[i].nxt)
	{ if(!bz[e[i].to]&&b[e[i].to]) clr(e[i].to);}
}
void dfs(int x,int y)
{
	if(x>n&&y==k)
	{
		for(int i=1;i<=n;i++) f[i]=N;
		for(int i=1;i<=n;i++) bz[i]=0;
		int res=0,fx=0;
		for(int i=1;i<=n;i++){ if(!bz[i]&&b[i]) fx++,clr(i);}
		if(fx>2) return ;
		for(int i=1;i<=n;i++){ if(b[i]) dfss(i,i,0);}
		for(int i=1;i<=n;i++) res=max(res,f[i]);
		ans=min(ans,res);
	}
	if(x>n||y>k) return ;
	b[x]=0,dfs(x+1,y);
	b[x]=1,dfs(x+1,y+1);
}
void sol()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) hd[i]=0,b[i]=0;
	cnt=0;
	for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
	if(k==n){ cout<<"0\n";return ;}
	ans=N+5,dfs(1,0);
	cout<<ans<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--) sol();
	return 0;
}

