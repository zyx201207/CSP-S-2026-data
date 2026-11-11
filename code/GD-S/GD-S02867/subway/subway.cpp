#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define ld long double
#define stg string
#define Cn const
using namespace std;
ll read() {
	ll r=0,fl=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') fl=-fl;c=getchar();}
	while(c>='0'&&c<='9') {r=(r<<3)+(r<<1)+(c^48);c=getchar();}
	return r*fl;
}
ll Max(ll a,ll b) {return a>b?a:b;}
ll Min(ll a,ll b) {return a<b?a:b;}
Cn ld eps=1e-9;
Cn ll Inf=1e18;
Cn int M=5e5+5,N=505;
vector<pair<int,ll> > G[M];
ll f[N][N];
int c,n,m,d,q,u,v,k;
ll w[M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++) {
		k=read();
		for(int j=1;j<=k;j++) {
			u=read();v=read();
			G[u].push_back(make_pair(i,v));
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) f[i][j]=Inf;
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) {
		for(auto x:G[i]) {
			for(auto y:G[i]) f[x.first][y.first]=Min(f[x.first][y.first],x.second+y.second);
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			for(int p=1;p<=n;p++) {
				f[j][p]=Min(f[j][p],f[j][i]+f[i][p]);
			}
		}
	}
	for(int i=1;i<=q;i++) {
		u=read();v=read();
		ll ans=Inf;
		for(auto x:G[u]) {
			for(auto y:G[v]) {
				//cout<<x.first<<" "<<y.first<<" "<<f[x.first][y.first]<<endl;
				ans=Min(ans,x.second+y.second+f[x.first][y.first]);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
}
