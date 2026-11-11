#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
ll maxn=-1e18;
ll n,m;
void dfs(ll cur,ll cnt,ll sum){
	if(cnt==m){
		maxn=max(maxn,sum);
		return;
	}
	if(cur>n)return;
	if(cnt==0){
		sum=a[cur];
		dfs(cur+1,cnt+1,sum);
		sum=0;
		dfs(cur+1,cnt,sum);
	}
	else{
		dfs(cur+1,cnt+1,(sum&a[cur]));
		dfs(cur+1,cnt,sum);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1,0,0);
	printf("%lld",maxn);
	return 0;
}
