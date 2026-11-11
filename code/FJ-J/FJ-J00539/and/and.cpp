#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N=200005;
int n,m,a[N],ans;
bool vis[N];
int dfs(int u,int now,int num){
	if(num==m){
		return now;
	}
	vis[u]=1;
	int ans=0;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			ans=max(ans,dfs(i,now&a[i],num+1));
		}
	}
	return ans;
}
signed main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		ans=max(ans,dfs(i,a[i],1));
		fill(vis+1,vis+n+1,0);
	}
	cout<<ans;
	/*
	4 2
	3 15 12 12
	
	5 3
	31 3 1 15 7
	*/
	return 0;
}
