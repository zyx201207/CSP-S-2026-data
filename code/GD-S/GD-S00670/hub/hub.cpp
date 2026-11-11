#include<bits/stdc++.h>
namespace zcy{
	using namespace std;
	typedef long long ll;
	typedef pair<int,int> pii;
	typedef pair<ll,ll> pll;
	const int MAXN=2e5+5;

	int n,k;
	vector<int>g[MAXN];

	void solve(){
		cin>>n;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
	}

	int main(){
		#ifndef DEBUG
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		#endif
		
		

		return 0;
	}
}
int main(){
	zcy::main();
	return 0;
}

