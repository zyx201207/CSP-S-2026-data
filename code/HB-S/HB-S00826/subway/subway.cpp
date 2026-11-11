#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
struct node{
	ll to,val;
}arr[500010];

ll dist[500010];
vector<node>e[500010];
ll c,n,m,d,q;
ll w[500010];

// u to v value = step u step v; + dij;

long long query(ll st,ll ed){
	ll ans=0;
	
	return ans+w[st]+w[ed];
}

*/

ll dist[2026][2026];
ll w[2026];
void solve(){
	int c,n,m,d,q;
	
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			dist[i][j]=0x3f3f3f3f3f;
		}
	}
	
	for(int i=1;i<=1000;i++){
		dist[i][i]=0;
	}
	
	for(ll i=1;i<=n;i++){
		ll aa,tt1,bb,tt2;
		cin>>aa>>tt1>>bb>>tt2;
		
		//e[aa].push_back({bb,tt1+tt2});
		//e[bb].push_back({aa,tt1+tt2});
		
		dist[aa][bb]=tt1+tt2;//min(dist[aa][bb],tt1+tt2);
		dist[bb][aa]=tt1+tt2;//min(dist[bb][aa],tt1+tt2);	
	}
	
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				//if(dist[i][k]+dist[k][j]<dist[i][j]){
				//	dist[i][j]=dist[i][k]+dist[k][j];
				//}
			}
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		//cout<<dist[x][y]+w[x]+w[y]<<endl;
	}
	
	/*
	if(c<=3){
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			for(int j=1;j<=k;j++){
				int aa,tt;
				cin>>aa>>tt;
				arr[j].a=aa,arr[j].t=tt;
			}
		}
		dfs(1);
	
	}
	
	if(7<=c && c<=11){
		
		for(ll i=1;i<=n;i++){
			ll aa,tt1,bb,tt2;
			cin>>aa>>tt1>>bb>>tt2;
			
			e[aa].push_back({bb,tt1+tt2});
			e[bb].push_back({aa,tt1+tt2});
		}
		
		while(q--){
			ll x,y;cin>>x>>y;
			ll dist[501010];
			bool ok[500010];
			priority_queue<pair< ll,ll>,vector< pair<ll,ll> >,greater<pair<ll,ll> > >q;
			
			memset(dist,0x3f,sizeof dist);
		
			dist[x]=0;
			q.push({0,x});
			while(q.size()){
				ll now=q.top().second;q.pop();
				if(ok[now]) continue;
				ok[now]=1;
				for(ll i=0;i<e[now].size();i++){
					ll nxt=e[now][i].to,w=e[now][i].val;
					
					if(dist[nxt]>dist[now]+w){
						dist[nxt]=dist[now]+w;
						q.push({dist[nxt],nxt});
					}
				}
			}
			cout<<dist[y]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			arr[j].a=aa,arr[j].t=tt;
		}
	}
	
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=n;j++){
			
		}
		
	}
	
	
	while(q--){
		int xxx,yyy;
		cin>>xxx>>yyy;
		
		cout<<query(xxx,yyy)<<endl;
	}
	
	
	*/
	
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
7 2 3 20 2
0 0 0  
2 1 2 2 3
2 2 3 3 1
1 3
1 2*/
// qwq// qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq// qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq// qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq// qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq// qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq// qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq// qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq// qwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwqqwq
