#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
vector<int> e[500000];
/*void dfs(int k){
	if(n==k){
		ans++;
		return 0;
	}
	for(int v:e[u])
}*/
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	cin>>c>>t;
	cout<<c<<t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<"0\n";
	}
	return 0;
}
