#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[5000005],ans,res;
ll dfs(ll mq,ll gs,int k){
	if(gs==m){
		return mq;
	}
	for(int i=k+1;i<=n;i++){
		res=max(res,dfs(mq&a[i],gs+1,i));
	}return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}for(int i=1;i<=n;i++){
		ans=max(ans,dfs(a[i],1,i));
	}printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}




































