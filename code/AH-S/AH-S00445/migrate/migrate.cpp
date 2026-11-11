#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e6+20;
long long c,t,n,d,a[N];
long long dfs(long long l,long long r){
	long long ans=0;
	if(a[r]-a[l]<=d) return 1;
	for(int i=l+1;i<=r-1;++i){
		ans+=dfs(l,i)*dfs(i,r);
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int l=1;l<=t;++l){
		long long ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				ans+=dfs(i,j);
			}
		}
		printf("%lld",ans);
	}
}
