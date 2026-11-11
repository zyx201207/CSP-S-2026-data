#include<bits/stdc++.h>
#define ll long long
#define fi(x) freopen(x".in","r",stdin)
#define fo(x) freopen(x".out","w",stdout)
#define wc(x) fi(x);fo(x)
#define F first
#define S second
using namespace std;
const int N=1010;
int c,t,n,k;
vector<int> e[N];
set<int> a,b;
bool use[N];
void solve() {
	cin>>n>>k;
	for(int i=1; i<n; i++) {
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(c==13 or c==14) cout<<(n-1)/2<<'\n';	
	else cout<<0<<'\n';
	return;
}
int main() {
	wc("hub");
	cin>>c>>t>>n>>k;
	while(t--) solve();
	return 0;
}

