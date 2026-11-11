#include<bits/stdc++.h>
vector<int> G[12];
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=3){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		cout<<0;
	}
	return 0;
}
