//GZ-J0027 张蔚远 贵阳白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx=-1;
int dfs(long long step,long long ans,long long k){
	if(k==m){
		mx=max(mx,ans);
		return 0;
	}
	else if(step==n+1){
		return 1;
	}
	if(ans==0){
		dfs(step+1,a[step],k+1);
	} 
	else{
	dfs(step+1,ans & a[step],k+1);
}
	dfs(step+1,ans,k); 
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1,0,0);
	printf("%lld",mx);
	return 0;
} 
