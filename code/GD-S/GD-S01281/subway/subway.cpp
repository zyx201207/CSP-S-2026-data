#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define ff(x) for(ll i=he[x],y,z;i;i=e[i].ne)
const ll N=505,M=5e5+5;
ll t,_,n,m,top,he[N],x,y,c,d,f[1005][1005],g[M];
struct xx{ll x,y;}q[N];
struct yy{ll w,h[25],t,l[25];}a[M];
struct zz{ll k,a[20],t[20];}b[N];
struct ww{ll to,ne,nu;}e[M];
void ji(ll x,ll y,ll z){e[++top]={y,he[x],z};he[x]=top;}
bool pd(xx x,xx y){return x.y<y.y;}
void up(ll x){while(x>1&&pd(q[x],q[x/2]))swap(q[x],q[x/2]);x>>=1;}
void dw(ll x){ll k=x;while(x*2<=t){k=x<<1;if(k<t&&pd(q[k+1],q[k]))k++;if(pd(q[x],q[k]))break;swap(q[k],q[x]);x=k;}}
xx pp(){xx o=q[1];q[1]=q[t--];dw(1);return o;}void ps(xx x){q[++t]=x;up(t);}
void b1(ll st){ps({st,0});while(t){xx x=pp();ff(x.x){y=e[i].to;z=e[i].nu;if(f[st][y]>x.y+z){f[st][y]=x.y+z;ps({y,f[st][y]});}}}}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>_;
	fo(i,1,m)cin>>a[i].w;
	fo(i,1,n)
	{
		cin>>b[i].k;
		fo(j,1,b[i].k)cin>>b[i].a[j]>>b[i].t[j];
	}
	if(c<=8)
	{
		fo(i,1,m)fo(j,1,m)f[i][j]=1e18;
		fo(i,1,n)
		{
			fo(j,1,b[i].k)
			{
				x=b[i].a[j];
				fo(k,1,j-1)f[x][b[i].a[k]]=f[b[i].a[k]][x]=b[i].t[j]+b[i].t[k];
			}
		}
		fo(k,1,m)fo(i,1,m)fo(j,1,m)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		while(_--)
		{
			cin>>x>>y;
			cout<<f[x][y]+a[x].w+a[y].w<<endl;
		}
		return 0;
	}
	if(9<=c&&c<=11)
	{
		fo(i,1,n)
		{
			if(b[i].k<2)continue;
			ji(b[i].a[1],b[i].a[2],b[i].t[1]+b[i].t[2]);
			ji(b[i].a[2],b[i].a[1],b[i].t[1]+b[i].t[2]);
		}
		fo(i,1,m)fo(j,1,m)f[i][j]=1e18;
		fo(i,1,m)f[i][i]=0;
		fo(i,1,m)b1(i);
		while(_--)
		{
			cin>>x>>y;
			cout<<f[x][y]+a[x].w+a[y].w<<endl;
		}
		return 0;
	}
	fo(i,1,n)
	{
		fo(j,1,b[i].k)
		{
			x=b[i].a[j];
			a[x].h[++a[x].t]=i;// on the i-th cricle
			a[x].l[a[x].t]=b[i].t[j];
		}
	}
	fo(i,1,n)fo(j,1,n)f[i][j]=1e18;
	fo(i,1,n)f[i][i]=0;
	fo(i,1,m)
	{
		fo(j,1,a[i].t)
		{
			fo(k,1,j-1)
			{
				// connect c a[i].h[j] and c a[i].h[k]
				f[a[i].h[j]][a[i].h[k]]=f[a[i].h[k]][a[i].h[j]]=a[i].l[j]+a[i].l[k];
			}
		}
	}
	fo(k,1,n)fo(i,1,n)fo(j,1,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	fo(i,1,m)
//	{
//		fo(j,1,a[i].t)cout<<a[i].h[j]<<" ";cout<<endl;
//	}
	while(_--)
	{
		cin>>x>>y;
		ll ans=1e18;
		fo(i,1,a[x].t)fo(j,1,a[y].t)if(a[x].h[i]==a[y].h[j])ans=min(ans,a[x].l[i]+a[y].l[j]);
		if(ans<1e18)
		{
			cout<<ans+a[x].w+a[y].w<<endl;
			continue;
		}
		fo(i,1,a[x].t)fo(j,1,a[y].t)if(a[x].h[i]!=a[y].h[j])
		{
//			ans=min(ans,f[a[x].h[i]][a[y].h[j]]+a[x].l[i]+a[y].l[j]));
		}
		cout<<ans+a[x].w+a[y].w<<endl;
	}
}
