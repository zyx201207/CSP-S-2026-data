#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m,a[N],p[N];
int erfen(int k,long long x){
	int l=1,r=k;
	while(l<r){
		int mid=(l+r)>>1;
		if((k-mid+1)*a[k]-(p[k]-p[mid-1])>m)l=mid+1;
		else r=mid;
	}
	return (k-r+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int x=erfen(i,a[i]);
		ans=max(ans,x);
	}
	printf("%d",ans);
	return 0;
}