#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+5,N = 2e3+5,INF = (1ll << 30) - 1;
int n,m,a[maxn],ans;
void dfs(int step,int ret,int cnt){
	if(step > n){
		if(cnt == m) ans = max(ans,ret);
		return ;
	}
	if(cnt == m){
		ans = max(ans,ret);
		return ;
	}
	for(int i = step + 1;i <= n;i++) dfs(i,ret & a[i],cnt+1);
	dfs(step+1,ret,cnt);
}
bool cmp(int p,int q){
	return p > q;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	ans = 0;
	for(int i = 1;i + m - 1 <= n;i++){
		int tmp = INF;
		for(int j = 1;j <= m;j++) tmp = tmp & a[i + j - 1];
		ans = max(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}
