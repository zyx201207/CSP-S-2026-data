#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200001],c[100001];
char b[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		c[i]=a[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]<c[r])
		{
			if(b[l]==b[r])
			{
				c[r]-=c[l];
				c[l]=0;
			}
			else
			{
				ans+=c[l];
				c[r]-=c[l];
				c[l]=0;
			}
			l++;
		}
		else if(c[l]==c[r])
		{
			if(b[l]==b[r])
			{
				c[l]=0;
				c[r]=0;
			}
			else
			{
				ans+=c[l];
				c[l]=0;
				c[r]=0;
			}
			l++;
			r--;
		}
		else if(c[l]>c[r])
		{
			if(b[l]==b[r])
			{
				c[l]-=c[r];
				c[r]=0;
			}
			else
			{
				ans+=c[r];
				c[l]-=c[r];
				c[r]=0;
			}
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
