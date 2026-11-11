#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,t,n,k,vis[6],cnt,ans=1e9,is[N];
vector<int>g[N];
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	for(int y:g[x])dfs(y);
}
void calc(int x,int c){
	if(c>k)return;
	if(x>n){
		cnt=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)if(!vis[i]){
			cnt++;dfs(i);
		}
		if(cnt!=2)return;
		int res=0;
		for(int x=1;x<=n;x++){
			int mn=1e9;
			for(int y:g[x]){
				if(is[y])mn=min(mn,)
			}
		}
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
}
signed main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	
	
}
