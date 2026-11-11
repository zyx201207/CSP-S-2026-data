//GZ-S00270 贵阳三中 王志栋 
#include<bits/stdc++.h>
using namespace std;
#define long long int
#define fi first
#define sc second
#define pii pair<int,int>

int c,n,m,d,q1;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	vector<int>w(m + 1),t(m + 1); 
	vector<vector<pair<int,int> > >g(m + 1);
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		for(int j = 1;j <= k;j++){
			int v,w;
			cin>>v>>w;
			if(v == i){
				t[v] = w;
			}
			else{
				g[i].push_back({v,w});
			}
		}
	}
	
	while(q1--){
		int U,V;
		cin>>U>>V;
		vector<int>dis(d + 1,1e9);
		priority_queue<pii,vector<pii >,greater<pii > >q;
		dis[U] = w[U] + t[U];
		q.push({w[U] + t[U],U});
		while(q.size()){
		 	int d = q.top().fi,u = q.top().sc;
		 	q.pop();
		 	if(d != dis[u])continue;
		 	for(auto vw:g[u]){
		 	 	int v = vw.fi,w = vw.sc;
		 	 	if(dis[v] > (dis[u] + w + t[v]) ){
		 	 		dis[v] = dis[u] + w + t[v];
		 	 		q.push({dis[v],v});
				  }
			}
		}
//		for(int i = 1;i <= m;i++){
//			cout<<dis[i]<<" ";
//		}
//		cout<<endl;
		cout<<dis[V] - t[V] + w[V]<<endl;
	}
	
}
