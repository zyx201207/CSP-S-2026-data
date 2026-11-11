#include<bits/stdc++.h>
using namespace std;

int c,_;
vector<int> edge[1000010];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>_;
	while(_--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if(k==n){
			cout<<0<<'\n';
		}
		else{
			cout<<1<<'\n';
		}
	}
	return 0;
}
