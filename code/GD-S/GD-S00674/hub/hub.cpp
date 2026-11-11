#include<bits/stdc++.h>
using namespace std;
//100+0+0+0=100
//AFO
#define MAXN 1001000
int c,t,n,k;
vector<int>g[MAXN];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v),g[v].push_back(u);
		}
		cout<<"";
	}
	return 0;
}
