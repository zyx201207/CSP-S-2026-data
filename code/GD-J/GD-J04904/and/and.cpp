#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int a[N],ans;
int n,m;

int dp[N];
bool vis[N];

void dfs(int d,int o){
	if(d > m){
		ans = max(ans,o); 
	}
	
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		int p = o & a[i];
		dfs(d+1,p);
		vis[i] = 0;
	}
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	for(int i = 1;i <= n;i++){
		vis[i] = 1;
		dfs(1,a[i]);
		vis[i] = 0;
	}
	
	cout<<ans;
	
	return 0;
}
