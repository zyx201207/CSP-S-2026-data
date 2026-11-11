#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int n,m;
int a[N];
int ans = 0;
void dfs(int t,int sum,int o,bool f){
	if(t == n + 1){
		if(o == m) ans = max(ans,sum);
		return;
	}
	if(f == 1){
		dfs(t + 1,sum,o,1);
		dfs(t + 1,a[t],o + 1,0);
		return;
	}
	dfs(t + 1,sum,o,0);
	if(o >= m) return;
	dfs(t + 1,sum & a[t],o + 1,0);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0,0,1);
	printf("%d\n",ans);
	return 0;
}
