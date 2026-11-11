#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],le,re,ans=1,mid,f;
void che(long long p){
	le=1;
	re=p;
	while(le<=re){
		mid=(le+re)/2;
		f=a[p]*(p-mid)-(d[p-1]-d[mid-1]);
		if(f>m){
			le=mid+1;
		}
		else{
			re=mid-1;
		}
	}
	ans=max(ans,p-le+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
	for(int i=1;i<=n;i++)che(i);
	printf("%lld",ans);
	return 0;
}
