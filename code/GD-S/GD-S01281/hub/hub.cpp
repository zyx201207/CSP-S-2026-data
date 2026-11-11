#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define ff(x) for(ll i=he[x],y;i;i=e[i].ne)
const ll N=1e6+5;
ll c,_,top,he[N],f[N],ans=1e18,h,t,q[N],n,k,b[N],x,y,mx,g[N];
struct ww{ll to,ne;}e[N<<1];
void ji(ll x,ll y){e[++top]={y,he[x]};he[x]=top;}
void dfs(ll x,ll fa)
{
	ll w=1;
	ff(x)
	{
		y=e[i].to;
		if(y==fa)continue;
		w=0;
		dfs(y,x);
		if(!b[x])g[x]+=g[y];
		else
		{
			if(b[y])g[x]+=g[y]-1;
			else g[x]+=g[y];
		}
	}
}
void bfs()
{
	h=t=mx=0;
	fo(i,1,n)
	{
		if(b[i])
		{
			q[++t]=i;
			f[i]=0;
//			cout<<i<<" ";
		}
		else f[i]=1e18;
	}
	while(h<t)
	{
		h++;
		ll x=q[h];
		ff(x)
		{
			y=e[i].to;
			if(f[x]+1<f[y])
			{
				f[y]=f[x]+1;
				q[++t]=y;
			}
		}
	}
	fo(i,1,n)mx=max(mx,f[i]);
	ans=min(ans,mx);
//	if(mx==1)cout<<"!!!";
//	cout<<endl;
}
void d1(ll x,ll y)
{
	if(y<0)return;
	if(x==n+1)
	{
		if(y>0)return;
		fo(i,1,n)g[i]=b[i];
		dfs(1,1);
//		fo(i,1,n)cout<<g[i]<<" ";cout<<endl;
		if(g[1]>2)return;
//	cout<<x<<" "<<y<<endl;
		bfs();
//		cout<<endl;
		return;
	}
	d1(x+1,y);
	b[x]=1;
	d1(x+1,y-1);
	b[x]=0;
}
void S()
{
	ans=1e18;
	cin>>n>>k;
	fo(i,1,n)he[i]=0;top=0;
	fo(i,1,n-1)
	{
		cin>>x>>y;
		ji(x,y);
		ji(y,x);
	}
	d1(1,k);
	cout<<ans<<endl;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>_;
	while(_--)S();
}
