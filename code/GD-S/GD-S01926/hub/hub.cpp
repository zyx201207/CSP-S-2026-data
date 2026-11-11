#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
vector<int>G[N];
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u); 
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdout);
	freopen("hub.out","w",stdout)
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
} 
