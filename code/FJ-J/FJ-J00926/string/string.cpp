#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a[2144442],l=0,sum=0;
char c[4353587];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int f=0;
	for(int i=2;i<=n;i++)
	{
		if(c[i]!=c[i-1])
		{
			f=1;
			break;
		}
	}
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]==a[r])
			{
				sum+=a[l];
				l++;
				r--;
			}
			else if(a[l]>a[r])
			{
				sum+=a[r];
				a[l]=a[l]-a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				sum+=a[l];
				a[r]=a[r]-a[l];
				l++;
			}
		}
		else
		{
			if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else if(a[l]>a[r])
			{
				a[l]=a[l]-a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]=a[r]-a[l];
				l++;
			}
		}
	}
	cout<<sum;
	return 0;
}
