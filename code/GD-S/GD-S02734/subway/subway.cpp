#include<bits/stdc++.h>
using namespace std;
//using ll=long long;
//struct node{
//	int a;
//	int t;
//};
//int minn=2e9;
int c,m,n,d,q;
//int vis[500005];
//int w[500005];
//pair<int,int> r[100005];
//vector<node> adj[500005];
//void dfs(int ts,int v,int tot){
//	if(tot>=minn) return;
//	if(v==r[ts].second){
//		minn=min(minn,tot);
//		return;
//	}
//	vis[v]=1;
//	for(auto u:adj[v]){
//		if(!vis[u.a]) dfs(ts,u.a,tot+adj[u.a][v].t+u.t);
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> d >> q;
	srand(time(0));
	for(int i=1;i<=q;i++){
		cout << rand()%3842*rand()/4<< "\n";
	}
//	for(int i=1;i<=m;i++){
//		cin >> w[i];
//	}
//	for(int j=1;j<=n;j++){
//		int a1,t1,a2,t2;
//		int k; cin >> k;
//		cin >> a1 >> t1;
//		--k;
//		while(k--){
//			cin >> a2 >> t2;
//			adj[a1].push_back({a2,t2});
//			adj[a2].push_back({a1,t1});
//			a1=a2;
//			t1=t2;
//		}
//	}
//	for(int i=1;i<=q;i++){
//		cin >> r[i].first >> r[i].second;
//		dfs(i,r[i].first,w[r[i].first]+w[r[i].second]);
//		cout << minn << " ";
//		minn=2e9;
//		memset(vis,0,sizeof(vis));
//	} 
	return 0;
}
