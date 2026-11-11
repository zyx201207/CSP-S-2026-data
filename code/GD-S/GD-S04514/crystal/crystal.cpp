#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
ll n,m,a[N],ans=0;
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		ll cnt=0;
		for(int j=i-x+1;j<=i;j++)
		{
			if(cnt > m)
			{
				break;
			}
			cnt+=a[i]-a[j];
			if(j==i)
			{
				if(cnt <= m)
				{
					return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool fb=true;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<n;i++)
	{
		if(a[i+1]-a[i] != a[i]-a[i-1])
		{
			fb=false;
		}
	}
	if(fb==true) 
	{
		int l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r) >> 1;
			if((a[1]+a[mid])*mid/2 <= m)
			{
				l=mid+1;
				ans=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		cout << ans << endl;
	}
	else
	{
		int l=1,r=n; 
		while(l <= r)
		{
			int mid=(l + r) >> 1;
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
		cout << ans << endl;
	}
	
	return 0;
} 
