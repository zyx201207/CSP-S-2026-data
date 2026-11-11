#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int a[N];
int n,m;
int ans=0;
void dfs(int u,int sum,int cnt){
	if(u==n+1||cnt==m){
		if(cnt==m) ans=max(ans,sum);
		return;
	}
	dfs(u+1,sum&a[u],cnt+1);
	dfs(u+1,sum,cnt);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++){
		dfs(i,a[i],0);
	}
	cout<<ans;
	return 0;
}