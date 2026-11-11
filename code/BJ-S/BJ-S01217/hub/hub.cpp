#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>g[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
	}
	return 0;
}
//ew76cg7w675x6h4xq976hx97x6q9    @_@
