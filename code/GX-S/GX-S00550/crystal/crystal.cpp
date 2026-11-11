#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N],sum[N];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			long long sum1=(i-mid+1)*a[i],sum2=sum[i]-sum[mid-1];
			if(sum1-sum2>m)l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d\n",ans);
	return 0;
}
