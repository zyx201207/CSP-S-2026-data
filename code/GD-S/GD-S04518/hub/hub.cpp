#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5,M=5e3+3;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;++i){
			int u,v;cin>>u>>v;
		}
		if(k>=n){
			cout<<0<<'\n';
			continue;
		}
		for(int i=2; ;++i){
			if(n/=i<=k){
				cout<<i-2<<'\n';
				break;
			}
		}
	}
	return 0;
}

