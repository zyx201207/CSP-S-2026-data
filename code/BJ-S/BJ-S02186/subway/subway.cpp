#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=505,M=500005;
inline void ckmax(int& x,int y){x=max(x,y);}
inline void ckmin(int& x,int y){x=min(x,y);}
int n,m,a[M],f[N][N],x,y,c,d,q,k;
vector<pi> v[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	rep(i,1,m) scanf("%lld",&a[i]);
	rep(i,1,n){
		scanf("%lld",&k);
		rep(o,1,k) scanf("%lld%lld",&x,&y),v[x].push_back({i,y});
	}
	rep(i,1,n) rep(j,1,n) f[i][j]=(i==j?0:1e18);
	rep(i,1,m) for(pi t1:v[i]) for(pi t2:v[i]){
		ckmin(f[t1.first][t2.first],t1.second+t2.second);
	}
	rep(k,1,n) rep(i,1,n) rep(j,1,n) ckmin(f[i][j],f[i][k]+f[k][j]);
	rep(i,1,q){
		scanf("%lld%lld",&x,&y);
		int ans=1e18;
		for(pi t1:v[x]) for(pi t2:v[y]) ckmin(ans,f[t1.first][t2.first]+t1.second+t2.second);
		printf("%lld\n",ans+a[x]+a[y]);
	}
	return 0;
}
