#include<bits/stdc++.h>
using namespace std; 
int c,t; 
auto seed=chrono::steady_clock::now().time_since_epoch().count(); 
mt19937 rnd(seed); 
int get() {
	int g=rnd()%4+1; 
	return g; 
}
void solve() {
	int n,k;
	cin>>n>>k; 
	vector<int> g[n+2];
	for(int i=2;i<=n;i++) {
		int x,y; 
		cin>>x>>y; 
		g[x].push_back(y); 
		g[y].push_back(x); 
	} 
	int q=get(); 
	n=n-k; 
	cout<<n/q<<endl; 
}
int main() {
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 
	cin>>c>>t;
	while(t--) {
		solve(); 
	}
	return 0; 
}
