#include<bits/stdc++.h>
using namespace std;
long long int a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n;
	cin>>n;
	long long int max_r=0;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		max_r+=a[i];
	}
	if(max_r%2==1)
	{
		max_r=(max_r+1)/2;
	}
	else
	{
		max_r=max_r/2;
	}
	long long int l=0,r=0,s=0;
	a[0]=1;
	for(long long int i=1;i<=n;i++)
	{
		r+=a[i];
		l=r-a[i]+1;
		r=min(r,max_r);
		long long int j=n;
		long long int l1=0,r1=0,ans=0;
		while(1)
		{
			r1+=a[j];
			l1=r-a[j]+1;
			if(r1>=l)
			{
				r1=min(r1,r);
				r1=min(r1,max_r);
				if(b[j]==b[i])
				{
					ans+=(r1-max(l1,l)+1);
				}
			}
			if(r1==r)
			{
				break;
			}
			j--;
		}
		s+=(r-l+1-ans);
	}
	cout<<s;
	return 0;
} 
