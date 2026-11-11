#include<bits/stdc++.h>
using namespace std;
int n,m,maxn = -1;

int vis[200010],a[200010];

void dfs(int ans,int t){
	
	if(t == 0){
		maxn = max(ans,maxn);
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i])
			if(t == m){
				vis[i] = 1;
				dfs(a[i],t - 1);
				vis[i] = 0;
			}else{
				vis[i] = 1;
				dfs(ans & a[i],t - 1);
				vis[i] = 0;
			}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	memset(vis,0,sizeof(vis));
	dfs(0,m);
	cout << maxn;
	return 0;
}
