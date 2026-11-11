#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> G[105];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i < n;i++){
			int u , v;
			cin >> u >> v;
			G[u].push_back(v);
		}
	}
	return 0;
} 
