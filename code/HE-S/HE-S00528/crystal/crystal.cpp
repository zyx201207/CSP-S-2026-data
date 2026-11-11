#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005];
bool bo=true,be=true;;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n-1;i++)
	{
		if(b[i]!=b[i+1])
		{
			be=false;
		}
	}
	if(be=true)
	{
		for(int i=1;i<=n;i++)
		{
		    if(i*(i-1)/2>m)
		    {
		    	cout<<i-1;
			}
		}
	}
	int mid=(n-1)/2+1;
	long long ans=0;
	int l;
	for(int j=1;j<=mid;j++)
	{
		ans+=a[mid]-a[j];
	}
	if(ans>m&&m>=ans-(a[mid]-a[mid-1]))
	{
		cout<<mid-1;
	    return 0;
	}
	else if(ans>m)
	{
		n=mid+1;
	}
	else
	{
		l=mid;
	}
	for(int i=l;i<=n;i++)
	{
		long long s=0;
		for(int j=1;j<=i;j++)
		{
			s+=a[i]-a[j];
		}
		if(s>m)
		{
			cout<<i-1;
		    break;
		}
	}
	return 0;
}
