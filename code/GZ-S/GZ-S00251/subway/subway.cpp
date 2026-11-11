//GZ-S00251 ¿Ó∫Ë’‹
#include<bits/stdc++.h>
#define endl '\n'
#define ls i<<1
#define rs (i<<1|1)
#define fi first
#define se second
#define pb push_back
using namespace std;
template<typename U,typename V>bool cmin(U &x,V y){return y<x?x=y,true:false;};
template<typename U,typename V>bool cmax(U &x,V y){return y>x?x=y,true:false;};
#define to(i,o,p) for(ll i=(o);i<=(p);i++)
#define un(i,o,p) for(ll i=(o);i>=(p);i--)
mt19937 rng(time(0));
using ll=long long;
using pii=pair<int,int>;
const int int_inf=1E9+7;
const ll inf=1E18+7;
const int mod=1E9+7;
const int P=0;
const int M=5E5+10;
const int N=5E2+10;
ll c,n,m,d,q,w[M],ans;//m,n don't mix up
vector<pii>G[N],o[M];
ll dis[N][N],W[N][N];
priority_queue<pii,vector<pii>,greater<pii>>p;
bool vis[N];
void dij(ll st){
	to(i,1,n)vis[i]=0;
	dis[st][st]=0;
	p.push({0,st});
	ll u,v,l;while(!p.empty()){
		u=p.top().se;p.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(pii x:G[u]){
			v=x.fi;l=x.se;
			if(cmin(dis[st][v],dis[st][u]+l)&&!vis[v])p.push({dis[st][v],v});
		}
	}
}
void solve(){//B
	cin>>c>>n>>m>>d>>q;
	to(i,1,m)cin>>w[i];
	ll k,u,v,l;to(i,1,n){//init
		cin>>k;
		to(j,1,k){
			cin>>u>>v;
			o[u].pb({i,v});
		}
	}
	to(i,1,n)to(j,1,n)W[i][j]=dis[i][j]=inf;
	to(i,1,m){//build
		for(pii x:o[i])for(pii y:o[i]){
			u=x.fi;v=y.fi;l=x.se+y.se;
			if(u==v)continue;
			cmin(W[u][v],l);
			cmin(W[v][u],l);
		}
	}
	to(i,1,n)to(j,i+1,n)if(W[i][j]!=inf){
		G[i].pb({j,W[i][j]});
		G[j].pb({i,W[i][j]});
	}
	to(i,1,n)dij(i);
	ll x,y;while(q--){
		cin>>x>>y;
		ans=inf;
		for(pii X:o[x])for(pii Y:o[y]){
			u=X.fi;v=Y.fi;
			cmin(ans,w[x]+X.se+dis[u][v]+Y.se+w[y]);
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("subway,in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

