#include<bits/stdc++.h>
using namespace std;
long long a[2000005][5];
char b[2000005];
char find(long long x)
{
	long long i=1;
	while(x<=a[i][2])
	{
		i++;
	}
	return b[i];
 } 
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long inx=1;
	for(long long i=1;i<=n;i++)
	{
		long long t1;
		cin>>t1>>b[i];
		a[i][1]=inx;
		a[i][2]=inx+t1-1;
		a[i][3]=t1;
		inx=inx+t1;
	}
	long long r=n,l=1,sum=0;
//	if(n%2==0)
//	{
		while(l<r)
		{
			if(b[l]!=b[r])
			{
				sum+=min(a[l][3],a[r][3]);
				if(a[l][3]<a[r][3])
				{
					a[r][3]=a[r][3]-a[l][3];
					a[r][2]=a[r][2]-a[l][3];
					l++;
				}
				else if(a[l][3]>a[r][3])
				{
					a[l][3]=a[l][3]-a[r][3];
					a[l][2]=a[l][2]+a[r][3];
					r--;
				}
				else
				{
					l++;
					r--;
				}
			}
			else
			{
				if(a[l][3]<a[r][3])
				{
					a[r][3]=a[r][3]-a[l][3];
					a[r][2]=a[r][2]-a[l][3];
					l++;
				}
				else if(a[l][3]>a[r][3])
				{
					a[l][3]=a[l][3]-a[r][3];
					a[l][2]=a[l][2]+a[r][3];
					r--;
				}
				else
				{
					l++;
					r--;
				}
			}
		}
//	}
//	else 
//	{
//		
//	}
	cout<<sum;
	return 0;
}
