#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,a[500005],ans,cnt,sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	for(int i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m){ r=mid;}
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
