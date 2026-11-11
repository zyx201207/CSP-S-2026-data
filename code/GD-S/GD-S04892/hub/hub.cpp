#include<bits/stdc++.h>

using namespace std;

int c,t,n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		vector<int> a[n];
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		cout<<a[n][2]<<'\n';
	}
	return 0;
} 
