#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],l=0,r=0,ans=0;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			ans+=min(a[l],a[r]);
			if(a[l]<a[r])
			{
				a[r]=a[r]-a[l];
				l++;
			}
			else if(a[l]>a[r])
			{
				a[l]=a[l]-a[r];
				r--;
			}
			else
			{
				l++;
				r--;
			}
		}
		else
		{
			if(a[l]<a[r])
			{
				a[r]=a[r]-a[l];
				l++;
			}
			else if(a[l]>a[r])
			{
				a[l]=a[l]-a[r];
				r--;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	printf("%lld",ans);
	
	return 0;
}
