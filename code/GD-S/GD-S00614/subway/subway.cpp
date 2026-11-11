#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=5e5+5,N=505;
int c,n,m,d,q,w[M];
ll dis[N][N];
vector<pair<int,int> > g[M];
void R(int &x){
	int f=1,c=getchar();x=0;
	while(c<48||c>57) f=(c=='-'?-1:1),c=getchar();
	while(c>=48&&c<=57) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=f;
}void W(ll x){if(x>9) W(x/10);putchar(x%10^48);}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	R(c),R(n),R(m),R(d),R(q);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=(i==j?0:1e18);
	for(int i=1;i<=m;++i) R(w[i]);
	for(int i=1;i<=n;++i){
		int k;R(k);
		for(int a,t;k--;)
			R(a),R(t),g[a].push_back({i,t});
	}for(int i=1;i<=m;++i){
		int len=g[i].size();
		for(auto x:g[i])
			for(auto y:g[i]) if(x!=y){
				int u=x.first,v=y.first;
				dis[u][v]=min(dis[u][v],(ll)x.second+y.second);
			}
	}for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int s,t;q--;){
		R(s),R(t);ll ans=1e18;
		for(auto u:g[s])
			for(auto v:g[t])
				ans=min(ans,dis[u.first][v.first]+u.second+v.second);
		W(ans+w[s]+w[t]),puts("");
	}
	return 0;
}
