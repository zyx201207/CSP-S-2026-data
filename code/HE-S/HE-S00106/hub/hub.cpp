#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=1e6+10;
int n,k;
vector<int> e[N];
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(k>=n) return cout<<"0\n",void();
	else{
		int p=(n+1)/2;
		cout<<(p-k+2)/4+1<<'\n';
	}
} 
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
} 
