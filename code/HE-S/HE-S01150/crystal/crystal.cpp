#include<bits/stdc++.h>
using namespace std;
long long int a[500009];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,lei=0,zwe=9999999999,z,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		lei+=a[i];
		//cout<<lei<<" "<<endl;
	}
	sort(a+1,a+n+1);
	/*for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}*/
	lei=lei/n;
	for(int i=1;i<=n;i++)
	{
		if(max(a[i],lei)-min(a[i],lei)<zwe)
		{
			zwe=max(a[i],lei)-min(a[i],lei);
			z=i;
		}
	}
	int l=z-1,r=z+1;
	//cout<<l<<" "<<r<<" "<<z<<" "<<zwe<<" "<<lei<<endl;
	for(int i=m;i>0;)
	{
		//cout<<i<<endl;
		if(l<=0)
		{
			l++;
		}if(r>n)
		{
			r--;
		}
		if(a[r]-a[z]>a[z]-a[l])
		{
			ans++;
			i=i-(a[z]-a[l]);
			a[l]=a[z];
			l--;
		}else if(a[r]-a[z]<=a[z]-a[l])
		{
			ans++;
			i=i-(a[r]-a[z]);
			a[r]=a[z];
			r++;	
		}
		//cout<<l<<" "<<r<<" "<<z<<" "<<i<<endl;
	}
	cout<<ans;
	return 0;
}
