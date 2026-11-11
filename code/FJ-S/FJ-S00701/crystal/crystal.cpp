#include<iostream>
#include<algorithm>
using namespace std;
long long a[500002],n,m,b[500002],c[500002];
bool checkkkk(int xxz)
{
	for(int i=1;i<=n-xxz+1;i++)
	{
		long long zong=b[i+xxz-2]-b[i-1]-(c[i+xxz-2]-c[i-1])*(i-1);
		if(zong<=m)
		{
//			if(xxz==315276)
//		cout<<i<<" "<<i+xxz-1<<" "<<zong<<"!!  "<<b[i+xxz-2]<<" "<<b[i-1]<<" "<<(c[i+xxz-2]-c[i-1])*(i-1)<<endl;
		return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	a[i]=a[i+1]-a[i];
	a[n]=0;
	b[1]=a[1];
	for(int i=2;i<n;i++)
	b[i]=a[i]*i+b[i-1];
	c[1]=a[1];
	for(int i=2;i<n;i++)
	c[i]=a[i]+c[i-1];
	a[0]=0;
	b[0]=0;
	c[0]=0;
	long long l=1,r=n;
	while(1)
	{
		if(l==r)
		break;
		int mid=(l+r+1)>>1;
//		if(mid==315276)
//		cout<<l<<" "<<r<<"!"<<endl;
		if(checkkkk(mid))
			l=mid;
			else
			r=mid-1;
//			cout<<mid<<"*"<<endl;
//			cout<<l<<" "<<r<<"%"<<endl;
	}
	cout<<l;
	return 0;
 } 
