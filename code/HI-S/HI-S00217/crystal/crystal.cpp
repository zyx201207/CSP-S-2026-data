#include<bits/stdc++.h>
using namespace std;
int n,l=1,r,mid,ans;
long long m,a[500010];
bool check(int x){
	long long sum=0;
	for(int i=1;i<x;i++) sum+=(a[x]-a[i]);
	for(int i=x+1;i<=n;i++){
		if(sum<=m) return 1;
		sum-=(a[i-1]-a[i-x]);
		sum+=(a[i]-a[i-1])*(x-1);
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	r=n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
