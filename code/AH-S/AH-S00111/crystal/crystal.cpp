#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long m;
/*bool check(int x)
{
	long long cnt=0;
	for(int i=1;i<=x;i++)
	{
		cnt+=(a[x]-a[i]);
		if(cnt>m)
		{
			return false;
		}
	}
	return true;
}*/
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);

/*		int l=1,r=n;
		int ans;
		while(l<=r)
		{
			int mid=(l+r) >> 1;
			if(check(mid))
			{
				l=mid+1;
				ans=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		cout<<ans;*/
	if(n<=5000)
	{
		int ma=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			long long s=0;
			int f=1;
			for(int j=i-1;j>=1;j--)
			{
				s+=a[i]-a[j];
				if(s>m)
				{
					ma=max(ma,i-j);
					f=0;
					break;
				}
			}
			if(f==1)
			{
				ma=max(ma,i);
			}
		}
		cout<<ma;
	}
	else
	{
		for(int i=n;i>=1;i--)
		{
			if((2*a[i]-a[i-1]-a[1])*(i-1)/2<=m)
			{
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
}
