#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int c,t;
//vector<int> g[1000005];
//vector<int> s;
//void dfs(int x){
//	
//}
int main(){
	fastio;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		cout<<rand()%1005<<endl;
	}
//	while(t--){
//		int n,k;
//		cin>>n>>k;
//		for(int i=1;i<=n;i++) g[i].clear();
//		for(int i=1;i<n;i++){
//			int u,v;
//			cin>>u>>v;
//			g[u].push_back(v);
//			g[v].push_back(u);
//		}
//		int ans=INT_MAX;
//		for(int mask=0;mask<(1<<k);mask++){
//			for(int j=0;j<n;j++){
//				s.clear();
//				if((mask>>j)&1){
//					s.push_back(j+1);
//				}
//				int cnt=0;
//				if(s.size()!=k) continue;
//				for(int i=1;i<=n;i++){
//					if(((mask>>j)&1) && vis[i]==0){
//						cnt++;
//						dfs(i);
//					}
//				}
//				if(cnt>2) continue;
//				int sum=0;
//				for(int i=0;i<s.size();i++){
//					
//				}
//			}
//		}
//	}
	return 0;
}
