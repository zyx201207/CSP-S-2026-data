#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[212345],ans,maxn,sum;
void dfs(int cnt,int sum,int u){
	if(cnt==m){
		ans=max(sum,ans);
		return;
	}
	for(int i=u+1;i<=n;i++){
		if(u==0) dfs(cnt+1,a[i],i);
		else dfs(cnt+1,(sum&a[i]),i);
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==1) sum=a[i];
		else sum=(sum&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(m==n){
		cout << sum;
		return 0;
	}
	if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i!=j) maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout << maxn;
		return 0;
	}
	if(m==1){
		cout << maxn;
		return 0;
	}
	dfs(0,0,0);
	cout << ans;
	return 0;
}
