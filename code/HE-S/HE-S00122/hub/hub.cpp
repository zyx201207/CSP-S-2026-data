#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k;
vector<int> G[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout<<n-k<<'\n';
	}
	return 0;
}
