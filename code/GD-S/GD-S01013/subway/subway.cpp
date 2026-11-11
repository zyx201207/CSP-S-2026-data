#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
const int N=800+10;
ll c,n,m,d,q,wr[N],ts[N][510],ar[N],dis[N],vis[N];
vector<pair<long long,long long>> vc[N];
bool f[N][510];
void dj(ll x){
	f(i,1,n){
		dis[i]=1e10;
		vis[i]=0;
	}
	dis[x]=0;
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> qu;
	qu.push({0,x});
	while(!qu.empty()){
		ll u=qu.top().second;
		qu.pop();
		if(vis[u])continue;
		vis[u]=0;
		for(auto o:vc[u]){
			ll to=o.first,v=o.second;
			if(dis[to]>dis[u]+v){
				dis[to]=dis[u]+v;
				qu.push({dis[to],to});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	f(i,1,m)cin>>wr[i];
	f(i,1,n){
		ll k;
		cin>>k;
		f(j,1,k){
			ll a;
			cin>>a;
			cin>>ts[i][a];
			f[i][a]=1;
		}
		ll mi=1e10;
		f(j,1,i-1){
			mi=1e10;
			f(r,1,m){
				if(f[j][r]&&f[i][r]){
					mi=min(ts[i][r]+ts[j][r],mi);
				}
			}
			vc[i].push_back({j,mi});
			vc[j].push_back({i,mi});
		}
	}
	
	f(i,1,q){
		ll a,b;
		cin>>a>>b;
		ll ans=1e18;
		f(i,1,n){
			if(f[i][a]){
				dj(i);
				ll mi=1e18;
	    		f(j,1,n){
		    		if(f[j][b]){
			    		mi=min(mi,ts[i][a]+dis[j]+ts[j][b]);
			    	}
//			    	cout<<dis[j]<<endl;
	    		}
				ans=min(mi,ans);
			}
		}
		cout<<wr[a]+ans+wr[b]<<endl;
	}
	return 0;
}
