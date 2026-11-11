#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5*1e5+10;
int a[N];
ll s=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	s/=n;
	ll minx=1e18;
	int mini;
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i]-s)<minx)
		{
			minx=abs(a[i]-s);
			mini=i;
		}
	}	
	for(int i=1;i<=n;i++)
	{
		if(mini!=i)
			a[i]=a[mini]-a[i];
	}
	a[mini]=0;
	sort(a+1,a+1+n);
	int i=1;
	while(a[i]<0)
		i++;
	ll t=a[i];
	int ans=0;
	for(;i<=n;i++)
	{
		if(a[i]<0)
			continue;
		if(m-(a[i]-t)>=0)
		{
			ans++;
			m-=(a[i]-t);
		}
	}
	cout<<ans;
	return 0;
}
