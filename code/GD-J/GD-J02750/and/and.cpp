#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=0;
bool vis[2*100001];
int a[2*100001];
void dfs(ll x,ll sum){
	if(x==m+1){
		ans=max(ans,sum);
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,sum&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1,(1<<30)-1);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
