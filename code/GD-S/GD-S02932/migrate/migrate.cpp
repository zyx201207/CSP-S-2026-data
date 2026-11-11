#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
#define inr(L,R,l,r) (l<=L and R<=r)
#define ofr(L,R,l,r) (L>r or l>R)
#define re return
#define ll long long
#define ull unsigned long long
#define ioo cin.tie(0)->sync_with_stdio(0);cout.tie(0)->sync_with_stdio(0);
using namespace std;
const int maxn=2e6+114;
ll x[maxn];
int r[maxn],l[maxn];
int f[maxn],g[maxn],s[maxn],t[maxn];
int vis[maxn];
void solve()
{
	int n;
	ll d;
	cin>>n>>d;
	rep(i,1,n) cin>>x[i],f[i]=g[i]=1;
	int R=1;
	rep(i,1,n)
	{
		R=i;
		while(R!=n and x[R+1]-x[i]<=d) R++;
		r[i]=R;
	}
	R=n;
	ir(i,1,n)
	{
		while(R!=1 and x[i]-x[R-1]<=d) R--;
		l[i]=R;
	}
	ll ans=0;
	rep(i,1,n) s[r[i]]++;
	rep(i,1,n) l[t[i]]++;
	rep(i,1,n)
	{
		rep(j,i+1,n)
		{
			int L=i,R=j;
			rep(x,1,n) vis[x]=0;
			while(r[L]!=L)
			{
				vis[L]++;
				L=min(j,r[L]);
				if(L==j) break;
			}
			while(l[R]!=R)
			{
				vis[R]++;
				R=max(i,l[R]);
				if(R==i) break;
			}
			int y=n+1,c=0;
			if(L!=j or R!=i) continue;
			rep(x,i+1,j-1)
			{
				if(vis[x]==1)
				{
					c++;
				}
			}
			if(c!=2) continue;
			rep(x,i+1,j-1)
			{
				if(vis[x]==1)
				{
					if(y==x-1) ans++;
					y=x;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
}
//完蛋了。
//打炸了。
 
