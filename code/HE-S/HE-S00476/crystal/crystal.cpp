//Oct31==Dec25?
#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],p[N],ans;
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	for(long long i=1;i<=n;i++)
	{
		long long l=1,r=i,res=i;
		while(l<=r)
		{
			long long mid=((l+r)/2);
			if(p[i]-p[mid-1]+m>=a[i]*(i-mid+1))r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}//14:50:22 AC
