#include<bits/stdc++.h>
using namespace std;
long long a[200010]; 
long long n;
long long sum,ans;
char x[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>x[i];
	}
//	sort(sum,sum+26);
	long long l=1,r=n;
	while(l<r)
	{
		if(x[l]!=x[r])
		{
			ans+=a[l];
			if(a[l]<a[r])
			{
				l++;
				a[r]-=a[l];
				a[l]=0;
			}
			else if(a[l]>a[r])
			{
				long long c=a[l];
				while(c>a[r])
				{
					c-=a[r];
					a[r]=0;
					r--;
				}
				if(c>0)
				{
					l++,a[r]-=c;
				}
				a[l]=0;
			}
			else l++,r--;
		}
		else
		{
			if(a[l]==a[r])
			{
				l++,r--;
			}
			else if(r-l>1)
			{	
				ans+=a[l];
				if(a[l]<a[r])
				{
					l++;
					a[r]-=a[l];
					a[l]=0;
				}
				else if(a[l]>a[r])
				{
					long long c=a[l];
					while(c>a[r])
					{
						c-=a[r];
						a[r]=0;
						r--;
					}
					if(c>0)
					{
						l++,a[r]-=c;
					}
					a[l]=0;
					}
			}
			else l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

