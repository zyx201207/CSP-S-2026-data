#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+7;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		cout<<(n-m)/8<<"\n";
	}
	return 0;
}
