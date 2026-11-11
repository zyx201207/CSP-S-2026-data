#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans = a[0];
void dfs(int x,int t,int sum){
	if(t == m){
		ans = max(ans,sum);
		return;
	}
	if(x>=n) return;
	
	if(t!= 0)dfs(x+1,t+1,sum&a[x]);
	if(t == 0) dfs(x+1,t+1,a[x]);
	dfs(x+1,t,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	dfs(0,0,0);
	printf("%d",ans);
	return 0;
}
