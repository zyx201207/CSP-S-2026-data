#include<bits/stdc++.h>
using namespace std;
long long n,l,r,ans;
long long a[200010],x,k=0;
string c[200010],y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if(i==1)
		{
			k++;
			a[k]=x;
			c[k]=y;
		}
		else if(y==c[k])
		{
			a[k]+=x;
		}
		else
		{
			k++;
			a[k]=x;
			c[k]=y;
			
		}
	}
	l=1;
	r=k;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
		}
		else if(a[l]<a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
		}
		else
		{
			if(c[l]!=c[r])
			{
				ans+=a[l];
			}
			a[l]=0;
			a[r]=0;
		}
		if(a[l]==0)
		{
			l++;
		}
		if(a[r]==0)
		{
			r--;
		}
	}
	cout<<ans;
	return 0;
}
