#include<bits/stdc++.h>  
using namespace std;
int n,ans;
long long m,a[500005],a1[500005],m2;
bool check(int x)
{
	m2=0;
	for(int i=1;i<=n;i++)
		a[i]=a1[i];
	for(int i=1;i<=x;i++)
	{
		m2+=(a[x]-a[i]);
		if(i+x<=n)
			a[i]=a[x+i-1]-a[i];
	}
	if(m2<=m)
	{
		return 1;
	}
	for(int i=x+1;i<=n;i++)
	{
		m2-=a[i-x];
		m2+=(a[i]-a[i-1])*(x-1);
		if(i+x<=n)
		{
			a[i]=a[i+x-1]-a[i];
		}
		if(m2<=m)
		{
			//cout<<"rt";
			return true;
		}
	}
	//cout<<"rf";
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a1[i];
	sort(a1+1,a1+n+1);
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		//cout<<l<<" "<<r<<endl;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
