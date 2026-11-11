#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t; vector<int>g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++) {
		int n,k; cin>>n>>k;
		for(int j=1;j<=n;i++) {
			int u,v; cin>>u>>v;
			g[u].push_back(v); g[v].push_back(u);
		}
		cout<<i<<"\n";
	}
}

