#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=-2e9;
bool vis[200005];
void dfs(int x,int p,int num) {
	vis[p]=1;
	num=(num&a[p]);
	if(x==m) {
		maxn=max(maxn,num);
		vis[p]=0;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i])dfs(x+1,i,num);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++)dfs(1,i,a[i]);
	printf("%d",maxn);
	return 0;
}
