#include<bits/stdc++.h>
using namespace std;
const long long RP=LONG_LONG_MAX;
long long C,T,n,m,a[112345],d[112345];
void dfs(long long u,long long now,long long step,long long maxs){
	if(now==n&&step==maxs)
		d[u]++;
	if(step>maxs)
		return ;
	for(int i=now+1;i<=n;i++)
		dfs(u,i,step+1,maxs);
	return ;
}
void pd(){
	long long l,r,s=0,ans=0;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld ",&a[i]);
	for(int i=1;i<=n;i++){
		l=i;s=0;
		while(l<n){
			r=lower_bound(a+1,a+n+1,l+m)-a;
			if(a[r]!=l+m) r--;
			l=r,s++;
		}
		dfs(i,i,0,s),ans+=(d[i]==2);
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld ",&C,&T);
	while(T--)
		pd();
	return 0;
}
