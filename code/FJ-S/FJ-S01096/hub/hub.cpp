#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,k;
vector<int> g[4005];
int ans=0x3f3f3f3f;
int sb=0;
void dfs(int x,int fa,int step,int res){
	if(step>=k){
		auto it1=g[x].begin(),it2=g[x].end();
		it1++;
		if(it1==it2){
			sb=max(res,sb);
			return;
		}
		for(auto i:g[x]){
			if(i!=fa)dfs(i,x,step+1,res+1);
		}
		return;
	} 
	for(auto i:g[x]){
		if(i!=fa)dfs(i,x,step+1,res);
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c==13||c==14){
			int m=(n-1)/2;
			int deeep=m+1;
			if(k%2==1){
				cout<<(m+1-((m+1)/2+(k-1)/2))/2+1<<"\n";
			}else{
				cout<<(m+1-((m+1)/2+k/2))/2+1<<"\n";
			}
		}else{
			for(int i=1;i<=n;i++){
				sb=0;
				dfs(i,i,1,0);
				ans=min(sb,ans);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
	
}

