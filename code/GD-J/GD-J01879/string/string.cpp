#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[200010];
char c[200010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long sum=0;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i] >> c[i];
		sum+=a[i];
	}
	long long l=sum/2,r=sum/2;
	long long li,ri,l0,r0;
	for(int i=1; i<=n; i++)
	{
		if(l>a[i])
		{
			l-=a[i];
		}
		else
		{
			li=i;
			l0=l;
			break;
		}
	}
	for(int i=n; i>=1; i--)
	{
		if(r>a[i])
		{
			r-=a[i];
		}
		else
		{
			ri=i;
			r0=r;
			break;
		}
	}
	long long ans=0;
	while(!(li==1 && l0==0))
	{
		if(l0>=r0)
		{
			if(c[li]!=c[ri])
			{
				ans+=r0;
			}
			l0-=r0;
			if(ri==n)
			{
				r0=0;
			}
			else
			{
				ri++;
				r0=a[ri];
			}
			if(l0==0 && li!=1)
			{
				li--;
				l0=a[li];
			}
		}
		else
		{
			if(c[li]!=c[ri])
			{
				ans+=l0;
			}
			r0-=l0;
			if(li==1)
			{
				l0=0;
			}
			else
			{
				li--;
				l0=a[li];
			}
		}
	}
	cout << ans << endl; 
	return 0;
}
