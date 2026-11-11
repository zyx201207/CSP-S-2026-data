#include <bits/stdc++.h>
#define up(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define dn(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define fst first
#define sed second
#define pref static inline
using namespace std;
using ll=long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vi=vector<int>;
using vl=vector<ll>;using vpi=vector<pii>;using vpl=vector<pll>;using pil=pair<int,ll>;
using vpil=vector<pil>;using pli=pair<ll,int>;using vpli=vector<pli>;
namespace my{
	const int N=505,M=5e5+5;
	const ll inf=1e18;
	int test,n,m,d,q,len[N];
	ll w[M],f[N][N],dist[N][N];
	vpil sub[N],change[M];
	bool vis[N];
	vpil g[N];
	void SOLVE(){
		cin>>test>>n>>m>>d>>q;
		up(i,1,m)cin>>w[i];
		up(i,1,n){
			cin>>len[i];
			up(j,1,len[i]){
				int x,w;cin>>x>>w;
				sub[i].push_back({x,w});
				change[x].push_back({i,w});
			}
		}
		up(i,1,n)up(j,1,n)f[i][j]=dist[i][j]=inf;
		up(x,1,n){
			for(auto tp:sub[x]){
				int v=tp.fst;
				ll w=tp.sed;
				for(auto kp:change[v]){
					int o=kp.fst;
					if(x==o)continue;
					dist[x][o]=min(dist[x][o],kp.sed+w);
				}
			}
			up(y,1,n)if(dist[x][y]<inf)g[x].push_back({y,dist[x][y]});
		}
//		up(i,1,n)up(j,1,n)cout<<dist[i][j]<<" \n"[j==n];
		up(start,1,n){
			up(i,1,n)vis[i]=false;
			priority_queue<pli,vpli,greater<pli>>q;
			q.push({f[start][start]=0,start});
			while(!q.empty()){
				int x=q.top().sed;
				q.pop();
				if(vis[x])continue;
				vis[x]=true;
				for(auto tp:g[x]){
					int v=tp.fst;
					ll nw=f[start][x]+tp.sed;
					if(f[start][v]>nw)
						q.push({f[start][v]=nw,v});
				}
			}
		}
//		up(i,1,n)up(j,1,n)cout<<f[i][j]<<" \n"[j==n];
		while(q--){
			int s,t;cin>>s>>t;
			ll ans=inf;
			for(pil tx:change[s])for(pil ty:change[t]){
				int x=tx.fst,y=ty.fst;
				ans=min(ans,f[x][y]+tx.sed+ty.sed);
			}
			cout<<ans+w[s]+w[t]<<'\n';
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int _=1;
	//cin>>_;
	while(_--)my::SOLVE();
	return 0;
}
