#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5000005],s[5000005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int c=m-(a[i]*i-s[i]);
		if(c>=0)
			ans=max(ans,i);
		else{
			int l=1,r=i;
			while(l<r)
			{
				int mid=(l+r)/2;
				if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)
					r=mid;
				else l=mid+1;
			}
			ans=max(ans,i-l+1);
		}
	}
	cout<<ans;
	return 0;
}

