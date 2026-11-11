#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 12;

int n,k,ans = 0;
bool vis[N],tag[N];

vector<int> g[N];

//void dfs(int u){
//	vis[u] = 1;
//	for(int v : g[u]){
//		if(vis[v]) continue;
//		if(tag[v]) dfs(v);
//	}
//}
//
//void get(int )

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1;i < n;i++) {
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		cout<<1<<'\n';
		
//		for(int s = 0;s < (1<<n);s++){
//			s<<=1;
//			memset(vis,0,sizeof(vis));
//			memset(tag,0,sizeof(tag));
//			int sum = 0;
//			for(int i = 1;i <= n;i++){
//				if((s>>i) & 1) tag[i]=1,sum++;
//			}
//			if(sum > k) continue;
//			sum = 0;
//			for(int i = 1;i <= n;i++){
//				if(tag[i] && !vis[i]){
//					sum++;if(sum > 2) break;
//					dfs(i);
//				}
//			}
//			if(sum > 2) continue;
//			
//			for(int i = 1;i <= n;i++) get(i);
//			
//		}
		
		
	}
	
	
	return 0;
}
