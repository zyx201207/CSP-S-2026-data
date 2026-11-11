#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k;
vector<int>e[1000005];
bool b[1000006];
void dfs(int fa,int u){
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
	return 0;
} 
