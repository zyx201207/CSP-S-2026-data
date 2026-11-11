#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+5;
vector<int> tr[N];
int dis[N];
void find(int u,int fa){
	for(auto v:tr[u]){
		if(v==fa) continue;
		dis[v]=dis[u]+1,find(v,u);
	}
}
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) tr[i].clear(),dis[i]=0;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		tr[u].push_back(v),tr[v].push_back(u);
	}
	dis[1]=0,find(1,0);
	int l1=1;
	for(int i=1;i<=n;i++) if(dis[i]>dis[l1]) l1=i;
	dis[l1]=0,find(l1,0);
	int l2=l1;
	for(int i=1;i<=n;i++) if(dis[i]>dis[l2]) l2=i;
	cout<<dis[l2]/3<<endl;
}
signed main(){
	//t4
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}
