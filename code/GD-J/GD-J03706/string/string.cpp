#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			if(a[l]==a[r])
			{
				l++;
				r--;
				continue;
			}
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
				continue;
			}
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
				continue;
			}
		}
		else
		{
			if(a[l]==a[r])
			{
				sum+=a[l];
				l++;
				r--;
				continue;
			}
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				sum+=a[r];
				r--;
				continue;
			}
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				sum+=a[l];
				l++;
				continue;
			}
		}
	}
	cout<<sum;
	return 0;
}

