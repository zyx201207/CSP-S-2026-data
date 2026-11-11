#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
constexpr int N = 5e5+505;
long long w[N];
long long c,n,m,d,q;
vector<PII> adj[N];
long long line_to_line[505][505];
long long dijkstra(int s,int t){
	s+=500,t+=500;
	priority_queue<PII,vector<PII>,greater<PII> > pq;
	vector<long long> dist(N,2e9);
	vector<bool> vis(N,false);
	dist[s] = 0;
	pq.push({0,s});
	vis[s] = true;
	while(!pq.empty()){
		PII f = pq.top();
		int fw = f.first,fu = f.second;
		pq.pop();
		if(dist[fu]<fw) continue;
		for(PII r:adj[fu]){
			int ru = r.first,rw = r.second;
			//cout<<fw<<" "<<fu<<" "<<ru<<" "<<rw<<endl;
			if(dist[ru]>rw+dist[fu]&&!vis[ru]){
				dist[ru]=rw+dist[fu];
				pq.push({dist[ru],ru});
				vis[ru] = true;
			}
		}
	}
	//cout<<endl;
	return dist[t];
}

bool isA,isB = true,isC; 
void solve(){
	for(int i = 1;i<=m;i++){
		cin>>w[i];
		if(w[i]!=w[1]) isB = false;
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			v+=500;
			adj[i].push_back({v,w});
			adj[v].push_back({i,w});
		}
	}
	while(q--){
		int st,fi;
		cin>>st>>fi;
		long long ans = 1e18;
		ans = dijkstra(st,fi)+w[st]+w[fi];
		cout<<ans<<'\n';
	}
	return;
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n<=2) isC = true;
	solve();
	cout<<flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
