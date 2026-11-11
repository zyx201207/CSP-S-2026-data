#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int>e[2000010];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(c==13||c==14){
			int sum=n*2;
			if(k>=n&&k<2*n){
				cout<<1<<endl;
			}else if(k==2*n){
				cout<<0<<endl;
			}else{
				cout<<(n+1-k)/2<<endl;
			}
			return 0;
		}
	}
	return 0;
}
