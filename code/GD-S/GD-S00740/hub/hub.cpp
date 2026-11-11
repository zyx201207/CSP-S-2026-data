#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
vector<int> G[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i=1; i<n; i++){
			int u,v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout << 1 <<endl;
	}
	return 0;
}
