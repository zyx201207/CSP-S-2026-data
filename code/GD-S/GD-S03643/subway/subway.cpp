#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
#define getc() (uu==vv&&(vv=(uu=In)+fread(In,1,1<<15,stdin),uu==vv)?EOF:*uu++)
char In[1<<15],*uu=In,*vv=In;
template<class T>
void R(T &x){
	char c=getc();bool f=0;x=0;
	for(;!isdigit(c);f|=(c=='-'),c=getc());	
	for(;isdigit(c);x=(x<<3)+(x<<1)+(c^48),c=getc());	
	f&&(x=-x);
}
using ll = long long;
const int M=5e5+5,N=505;
const ll inf=1e18;
int c,n,m,d,q,w[M],k,x,t;
vector<pair<int,int>>g[M];
ll dis[N][N];
void solve(){
	R(c),R(n),R(m),R(d),R(q);
	rep(i,1,m)R(w[i]);
	memset(dis,0x3f,sizeof dis);
	rep(i,1,n){
		R(k);dis[i][i]=0;
		while(k--)R(x),R(t),g[x].push_back({i,t});
	}
	rep(i,1,m)
		for(auto u:g[i])
			for(auto v:g[i])
				if(u.first^v.first)dis[u.first][v.first]=u.second+v.second;
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v;R(u),R(v);
		ll ans=inf;
		for(auto s:g[u])
			for(auto t:g[v])
				ans=min(ans,dis[s.first][t.first]+s.second+t.second);
		cout<<ans+w[u]+w[v]<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
