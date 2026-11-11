#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
typedef unsigned long long ll;
ll n,m,d,Q,dis[N+M],W[N],di[N][N];
bool f[N+M];
vector<pair<int,ll>> e[N+M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		ll k,u=m+i;
		cin>>k;
		for(int j=0;j<k;j++){
			ll v,w;
			cin>>v>>w;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
	}
	for(int i=1;i<=n;i++){
		int u1=i+m,kk=1;
		memset(f,0,sizeof(f));
		f[u1]=1;
		priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
		for(auto ee:e[u1]){
			int v=ee.first;
			ll w=ee.second;
			q.push({w,v});
		}
		while(1){
			pair<ll,int> ee=q.top();
			q.pop();
			ll w=ee.first,v=ee.second;
			if(f[v]){
				continue;
			}
			f[v]=1;
			dis[v]=w;
			if(v>=m+1){
				di[i][v-m]=w;
				if(++kk==n){
					break;
				}
			}
			for(auto e1:e[v]){
				ll w1=w+e1.second,v1=e1.first;
				q.push({w1,v1});
			}
		}
	}
	while(Q--){
		int u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(auto ee:e[u]){
			int u1=ee.first-m,w1=ee.second;
			for(auto e1:e[v]){
				int v1=e1.first-m,w2=e1.second;
				ans=min(ans,di[u1][v1]+W[u]+W[v]+w1+w2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}