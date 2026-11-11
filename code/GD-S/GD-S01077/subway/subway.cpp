#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define ROF(i,a,b) for(int i=(int)b;i>=(int)a;i--)
#define ll long long
#define ull unsigned long long
const int N=1e6+10;
const ll mod=1e9+7;
const ll inf=1e18+10;
using Vl=vector<int>;
using PI=array<ll,2>;
int cid,n,m,d,q,h[N],cte=1;ll dis[N],ans[N],W[N];
vector<PI> que[1000010];
struct E{int v,nxt;ll w;}e[N<<2];
inline void Ae(int u,int v,ll w){e[++cte]={v,h[u],w};h[u]=cte;e[++cte]={u,h[v],w};h[v]=cte;return ;}
//double STT;
//inline double TESI(){return 1.0*(clock()-STT)/CLOCKS_PER_SEC;}
bool is[N];
inline void DJ(int st){
	fill(dis+1,dis+n+m+1,inf);int ct=0;
	priority_queue<PI> q;q.push({dis[st]=0,st});
	for(auto v:que[st]) is[v[0]]=1;
	FOR(i,1,n) ct+=is[i];
	while(!q.empty()){
		PI tp=q.top();q.pop();
		ll dd=-tp[0];int u=tp[1];
		if(dd!=dis[u]) continue;
		if(is[u]){
			is[u]=0;
			if(!--ct){
				for(auto v:que[st]) ans[v[1]]+=dis[v[0]];
				return ;
			}
		}
		for(int ei=h[u];ei;ei=e[ei].nxt){
			int v=e[ei].v;ll w=e[ei].w;
			if(dis[v]>dis[u]+w) q.push({-(dis[v]=dis[u]+w),v});
		}
	}return ;
}
namespace Sparkle1{
	PI w[N];
	int main(){
		FOR(i,0,1){
			int k;cin>>k;
			FOR(j,1,k){int x;cin>>x>>w[x][i];}
		}
		ll mn=inf;
		FOR(i,1,n) if(w[i][0]&&w[i][1]) mn=min(mn,w[i][0]+w[i][1]);
		while(q--){
			int x,y;cin>>x>>y;
			ll ans=inf,res=W[x]+W[y];
			if(w[x][0]){
				if(w[y][0]) ans=w[x][0]+w[y][0];
				if(w[y][1]) ans=min(ans,w[x][0]+w[y][1]+mn);
			}
			if(w[x][1]){
				if(w[y][1]) ans=min(w[x][1]+w[y][1],ans);
				if(w[y][0]) ans=min(ans,w[x][1]+w[y][0]+mn);
			}
			cout<<ans+res<<'\n';
		}
		return 0;
	}
}
namespace Sparklezj{
	ll to[510][510];
	int main(){
		FOR(i,n+1,n+m-1){
			fill(dis+1,dis+n+m+1,inf);
			int ct=m-i;
			priority_queue<PI> q;q.push({dis[i]=0,i});
			while(!q.empty()){
				PI tp=q.top();q.pop();
				ll dd=-tp[0];int u=tp[1];
				if(dd!=dis[u]) continue;
				if(!(ct-=u>n+i)) break;
				for(int ei=h[u];ei;ei=e[ei].nxt){
					int v=e[ei].v;ll w=e[ei].w;
					if(dis[v]>dis[u]+w) q.push({-(dis[v]=dis[u]+w),v});
				}
			}
			FOR(j,1,m) to[i-n][j]=to[j][i-n]=dis[j+n];
		}
//		FOR(i,1,m) FOR(j,1,m) cout<<to[i][j]<<" \n"[j==m];
		while(q--){
			int x,y;cin>>x>>y;ll ans=inf;
			for(int ei=h[x];ei;ei=e[ei].nxt){
				int v=e[ei].v;ll w=e[ei].w;
				for(int ei1=h[y];ei1;ei1=e[ei1].nxt){
					int v1=e[ei1].v;ll w1=e[ei1].w;
					ans=min(ans,w+w1+to[v-n][v1-n]);
				}
			}
			cout<<ans+W[x]+W[y]<<'\n';
		}
//		cout<<TESI()<<'\n';
		return 0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
//	STT=clock();
	cin>>cid>>m>>n>>d>>q;
	FOR(i,1,n) cin>>W[i];
	if(m==2&&1ll*min(n,q)*n>40000000) return Sparkle1::main();
	FOR(i,1,m){
		int k;cin>>k;
		FOR(j,1,k){
			int v;ll w;cin>>v>>w;Ae(i+n,v,w);
		}
	}
	if(1ll*min(n,q)*n<=40000000){
		FOR(i,1,q){int l,r;cin>>l>>r;que[l].push_back({r,i});ans[i]=W[l]+W[r];}
		FOR(i,1,n) if(!que[i].empty()) DJ(i);
		FOR(i,1,q) cout<<ans[i]<<"\n";
		return 0;
	} 
	return Sparklezj::main(); 
}
/*
0 2 5 20 10
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5

17
32
17
31
17
16
16
31
25
30


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

