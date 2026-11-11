#include<bits/stdc++.h>
using namespace std;
int n,c,t,k,deep[1000005];vector<int> T[1000005];
void dfs(int now,int deeps){
	deep[now]=deeps;
	for(auto i:T[now])dfs(i,deeps+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;int ans=1e6;
		for(int i=1;i<=n;i++)T[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;if(u>v)swap(u,v);
			T[u].push_back(v);
		}
		if(n==k)cout<<"0\n";
		else{
			dfs(1,1);
			int deepmax=0;
			for(int i=1;i<=n;i++)deepmax=max(deepmax,deep[i]);
			ans=n/k-1;
			cout<<ans<<'\n';
		}
	}
	return 0;
}
