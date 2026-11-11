#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=4e18+7;
int c,n,m,d,q;
vector<int> w,ans;
vector<vector<pair<int,int>>> r;
int dij(int s,int e){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	vector<int> dist(m+1,INF);
	dist[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int d=q.top().first,u=q.top().second;
		q.pop();
		if(d>dist[u]) continue; 
		for(auto it:r[u]){
			int v=it.first,t=it.second;
			if(dist[v]>dist[u]+t){
				dist[v]=dist[u]+t;
				q.push({dist[v],v});
			}
		}
	}
	return dist[e];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+1);
	r.resize(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int> v(k+1),t(k+1);
		for(int j=1;j<=k;j++){
			cin>>v[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int a=j+1;a<=k;a++){
				r[v[j]].push_back({v[a],t[j]+t[a]});
				r[v[a]].push_back({v[j],t[j]+t[a]});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<'\n';
	} 
	return 0;
}
