#include<bits/stdc++.h>
using namespace std;
unsigned long long b[5005][5005],c[500005],m,h;
int n,f;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	if(n<=5000)
	{
		for(int s=1;s<=n;s++)cin>>a[s],c[s]=a[s]-a[s-1];
		for(int s=1;s<=n;s++)
		{
			unsigned long long g=1;
			for(int d=s+1;d<=n;d++,g++)
			{
				b[s][d]=b[s][d-1]+g*c[d];
			}
		}
		for(int s=1;s<=n;s++)
		{
			int l=0,r=s-1;
			while(l<r)
			{
				int mid=(l+r+1)/2;
				if(b[s-mid][s]<=m)l=mid;
				else r=mid-1;
			}
			f=max(f,l);
		}
		cout<<f+1;
	}
	else
	{
		for(int s=1;s<=n;s++)cin>>a[s],c[s]=c[s-1]+s;
		h=a[2]-a[1];
		for(int s=1;s<=n;s++)
		{
			unsigned long long g=1;
			for(int d=s+1;d<=n;d++,g++)
			{
				b[s][d]=b[s][d-1]+g*c[d];
			}
		}
		int l=0,r=n-1;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(c[mid]<=m)l=mid;
			else r=mid-1;
		}
		cout<<l;
	}
	return 0;
}
