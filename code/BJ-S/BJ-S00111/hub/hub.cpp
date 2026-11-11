#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a[2000005],vis[2000005];
vector<int>vt[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(vis,0,sieof(vis));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		cout<<(n-1)/2<<endl;
		
	}
	return 0;
}
