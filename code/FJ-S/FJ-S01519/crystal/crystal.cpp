#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long sum[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i-1;
		while(l<r)
		{
			int mid=l+r>>1;
			if(a[i]*(i-1-mid)-(sum[i-1]-sum[mid])<=m)
			{
//				cout<<a[i]*(i-1-mid)<<' '<<(sum[i-1]-sum[mid])<<' '<<m<<'\n';
				r=mid;
			}
			else l=mid+1;
		}
//		cout<<i<<' '<<l<<'\n';
		ans=max(ans,i-l);
	}
	printf("%d",ans);
	return 0;
}
/*
5 5
1 2 5 10 8 
*/
