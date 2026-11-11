#include <bits/stdc++.h>
#define up(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define dn(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define fst first
#define sed second
#define pref static inline
using namespace std;
using ll=long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vi=vector<int>;
using vl=vector<ll>;using vpi=vector<pii>;using vpl=vector<pll>;using pil=pair<int,ll>;
using vpil=vector<pil>;
namespace my{
	const int N=1e6+5,inf=1e9;
	int n,k;
	vi g[N];
	int dist[N];
	bool vis[N];
	void SOLVE(){
		cin>>n>>k;
		up(i,2,n){
			int x,y;
			cin>>x>>y;
			x--,y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ans=inf;
		int U=1<<n;
		up(S,1,U-1){
			up(i,0,n)vis[i]=false;
			int t=0;
			up(i,0,n-1){
				if(!((S>>i)&1))continue;
				if(vis[i])continue;
				queue<int>q;
				q.push(i);
				t++;
				while(!q.empty()){
					int k=q.front();q.pop();
					for(int v:g[k])if(!vis[v])q.push(v),vis[v]=true;
				}
			}
			if(t<=2){
				int ret=0;
				up(i,0,n-1)if(!((S>>i)&1)){
					up(i,0,n)vis[i]=false,dist[i]=0;
					queue<int>q;q.push(i);
					while(!q.empty()){
						int k=q.front();q.pop();
						for(int v:g[k])if(!vis[v])q.push(v),dist[v]=dist[k]+1,vis[v]=true;
					}
					int mn=inf;
					up(i,0,n-1)if((S>>i)&1)mn=min(mn,dist[i]);
					if(vis[i])continue;
					ret+=mn;
				}
				ans=min(ans,ret);
			}
		}cout<<ans<<'\n';
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int _=1,test;cin>>test>>_;
	while(_--)my::SOLVE();
	return 0;
}

