#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=1e6+5;
int t,n,k;
vector<int> e[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i) e[i].clear();
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;e[u].push_back(v),e[v].push_back(u);
		}cout<<n-k<<'\n';
	}
	return 0;
}
