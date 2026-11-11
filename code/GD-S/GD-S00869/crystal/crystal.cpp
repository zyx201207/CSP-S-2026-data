#include<bits/stdc++.h>
int n,i,j,f,l,r,mid;
long long m,ans,a[500002],s[500002],k;
bool check(int x){
	for(i=1;i+x-2<n;++i)
		if(a[i+x-1]*x-s[i+x-1]+s[i-1]<=m)
		return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m),r=n;
	for(i=0;++i<=n;)
		scanf("%lld",a+i);
	std::sort(a+1,a+n+1);
	for(i=0;++i<=n;)
		s[i]=s[i-1]+a[i];
	while(l<r)
		check(mid=l+r>>1)?
			l=mid:r=mid-1;
	printf("%d",l);
}
