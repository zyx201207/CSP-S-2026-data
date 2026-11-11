#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,ans,have[N],vis[N],dist[1111][1111];
vector<int>T[N];
vecotr<int>hubs;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0x3f3f3f3f;
		int n,k;cin>>n>>k;for(int i=1;i<=n;i++)T[i].clear(),f[i]=i;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			T[u].push_back(v),T[v].push_back(u);
		}
		cout<<1<<endl;
	}
	return 0;
}
