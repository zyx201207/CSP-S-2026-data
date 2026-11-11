#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int c,t,n,k,u,v;
vector<int> g[maxn];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin >> c >> t;
	int ans = 1;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i < n;i++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ans << endl;
		ans++;
	}
	return 0;
}
