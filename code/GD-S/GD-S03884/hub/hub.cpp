#include <bits/stdc++.h>
using namespace std;
int n,k;
void solve(){
	cin>>n>>k;
	int u,v;
	for(int i=1;i<n;++i) cin>>u>>v;
	cout<<((n+1)/2-k)/4+1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
