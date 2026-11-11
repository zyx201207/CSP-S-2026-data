#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e6+7;
int c,T;
int n,k;
vector<int> e[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout<<n-1<<endl;
}
int32_t main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
