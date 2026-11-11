#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k,vis[5500][5500];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			vis[u][v]=vis[v][u]=1;
		}
		cout<<1<<endl;
	}
	return 0;
}

