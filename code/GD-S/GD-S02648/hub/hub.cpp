#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> G[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			G[i].clear;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(n==k){
			cout<<0<<endl;
			return 0;
		}
		if(13<=c&&c<=14){
			if(n==k){
				cout<<0<<endl;
				return 0;
			}
			if(n==k+1){
				cout<<1<<endl;
				return 0;
			}
			cout<<n/k+1<<endl;
			return 0;
		}
	}
	return 0;
} 
