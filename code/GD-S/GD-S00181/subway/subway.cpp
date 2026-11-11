#include<bits/stdc++.h>
using namespace std;
#define ll int
#define LL long long
#define put(x) cerr<<x<<'\n'
ll read(){ll x=0,w=1;char c=getchar();while('0'>c||'9'<c){if(c=='-')w=-1;c=getchar();}while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}return x*w;}
const ll N=505,M=5e5+10;const LL inf=0x3f3f3f3f3f3f3f3f;
LL dis[N][N],E[N][N];
ll n,q,m,d;
struct mqm{
	ll u;LL val;
	bool operator <(const mqm &x)const{
		return val>x.val;
	}
};
struct mqmh{
	ll u;ll val;
};
vector<mqmh>dt[M];
//vector<ll>zt[N];

priority_queue<mqm>qu;
bool vis[N];
set<ll>st;
void dik(ll s){
	st.clear();
	for(ll i=1;i<=n;i++){
		vis[i]=0,st.insert(i);
		dis[s][i]=inf;
	}
	dis[s][s]=0;qu.push((mqm){s,0});
	while(qu.size()){
		ll u=qu.top().u;qu.pop();
		if(vis[u])continue;
		vis[u]=1;st.erase(u);
		for(auto it=st.begin();it!=st.end();it++){
			ll v=*it;
			if(dis[s][v]>dis[s][u]+E[u][v]){
				dis[s][v]=dis[s][u]+E[u][v];qu.push((mqm){v,dis[s][v]});
			}
		}
	}
}
ll C;
LL w[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	auto stt=clock();
	C=read();n=read(),m=read(),d=read(),q=read();
	memset(E,0x3f3f,sizeof E);
	for(ll i=1;i<=m;i++)w[i]=read();
	for(ll i=1;i<=n;i++){
		ll k=read();
		for(ll j=1;j<=k;j++){
			ll u=read();ll t=read();
//			zt[i].push_back(u);
			for(ll x=0;x<dt[u].size();x++){
				ll v=dt[u][x].u;
				E[i][v]=E[v][i]=min(E[i][v],(LL)dt[u][x].val+(LL)t);
			}
			dt[u].push_back((mqmh){i,t});
		}
	}
	for(ll i=1;i<=n;i++)dik(i);
	while(q--){
		ll u=read(),v=read();
		LL as=inf;
		for(ll i=0;i<dt[u].size();i++)for(ll j=0;j<dt[v].size();j++)as=min(as,(LL)dt[u][i].val+(LL)dt[v][j].val+dis[dt[u][i].u][dt[v][j].u]);
		cout<<(LL)(as+w[u]+w[v])<<'\n';
	}
//	auto ed=clock();
//	cerr<<ed<<"ms\n";
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
