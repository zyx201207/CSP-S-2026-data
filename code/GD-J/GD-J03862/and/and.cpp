#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
long long n,m,a[N],ans;
void dfs(long long k,long long g,long long zz){
	if(k>=m){
		ans=max(ans,zz);
		return ;
	}if(g>n) return ;
	if(k==0) zz=a[g];
	for(int i=g;i<=n;i++){
		dfs(k+1,i+1,zz&a[i]);
		dfs(k,i+1,zz);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,1,0);
	printf("%lld",ans);
	return 0;
}
