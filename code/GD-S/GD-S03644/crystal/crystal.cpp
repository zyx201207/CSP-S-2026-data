#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,S,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;scanf("%lld",a+i++));
	sort(a,a+n);for(int i=1;i<=n;a[i]+=a[i-1],i++);
	for(int i=1,j=0;i<=n;ans=max(ans,i-j),i++)
		for(;(a[i]-a[i-1])*(i-j)>m+a[i]-a[j];j++);
	printf("%d",ans);
	return 0;
}
