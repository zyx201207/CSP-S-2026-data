#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int N=50005;
int dist[N];
vector<pii>g[N];

void dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	pq.push({0,s})
	dist[s]=0;
	while(!pq.empty()){
		int v=pq.top().second;
		pq.pop();
		for(int i=0;i<;i++){
			int u=g[i].first;
			int w=g[i].second;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
			}
		}
		pq.push({u,})
	}
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll c,n,m,d,q;
	cin>>n>>m;
	
	dijkstra(0);
	
	return 0;
} 
