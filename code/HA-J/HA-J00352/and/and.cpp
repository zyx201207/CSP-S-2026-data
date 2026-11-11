#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int MAXN = 200005;
int a[MAXN];
bool vis[MAXN];
int ans = -1;
int n,m;

void dfs(int v,int cnt,int as){
	if(cnt == m){
		ans = max(ans,v);
		return ;
	}
	if(as == n){
		return ;
	}
	for(int i=as+1;i<=n;i++){
		if(vis[i] == 1){
			continue;
		}
		vis[i] = 1;
		dfs(v&a[i],cnt+1,i);
		vis[i] = 0;
	}
	return ;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n-m;i++){
		vis[i] = 1;
		dfs(a[i],1,i);
		vis[i] = 0;
	}
	cout << ans;
	return 0;
}