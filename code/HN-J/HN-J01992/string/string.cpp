#include <bits/stdc++.h>
using namespace std;
int a[200010],c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d %c",&a[i],&c[i]);
	int l=1,r=n;
	long long ans=0;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]<a[r]) a[r]-=a[l],l++;
			else if(a[l]==a[r]) a[l]=a[r]=0,l++,r--;
			else a[l]-=a[r],r--;
		}
		else
		{
			if(a[l]<a[r]) ans+=a[l],a[r]-=a[l],l++;
			else if(a[l]==a[r]) ans+=a[l],a[l]=a[r]=0,l++,r--;
			else ans+=a[r],a[l]-=a[r],r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
