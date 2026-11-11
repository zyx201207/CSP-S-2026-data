#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll=long long;
using pii=pair<int,int>;

const int N=2e6+5;

int n,k;
vector<int> g[N];

void solve(){
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c,t;cin>>c>>t;
	while(t--) solve();

	return 0;
}