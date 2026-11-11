#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int sum[200010],a[200010];
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	int ans=0;
	while(l<r)
	{
		if(a[l]==a[r])
		{
			if(c[l]==c[r]) l++,r--;
			else ans+=a[l],l++,r--;
		}
		else if(a[l]<a[r])
		{
			if(c[l]==c[r])
			{
				a[r]-=a[l];
				sum[r]-=a[l];
				l++;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l];
				sum[r]-=a[l];
				l++;
			}
		}
		else
		{
			if(c[l]==c[r])
			{
				a[l]-=a[r];
				sum[l]+=a[r];
				r--;
			}
			else
			{
				ans+=a[r];
				a[l]-=a[r];
				sum[l]+=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
