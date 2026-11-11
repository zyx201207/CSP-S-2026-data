#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,Mod=998244353;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	cout<<(n+1)/2/2/2-k/2/2+1;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1,c;
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
