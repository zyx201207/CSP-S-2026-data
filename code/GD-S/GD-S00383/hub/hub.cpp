#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	int num=1;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<vector<int> >g;
		g.resize(n+1); 
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<num;
		num++;
	}
	return 0;
}
