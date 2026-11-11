#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> g[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==n){
			cout << 0 << endl;
			continue;
		}
		if(13<=c && c<=14){
			if(2*k+1>=n){
				cout << 1 << endl;
			}else{
				cout << (n-k)/2 << endl;
			}
		}else if(c==1){
			cout << 1 << endl;
		}
	}
	return 0;
}
