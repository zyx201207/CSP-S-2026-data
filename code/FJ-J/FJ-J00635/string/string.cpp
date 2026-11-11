#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
int b[200005];
char a1;
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long l,r,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>a1;
		b[i]=int(a1)-96;
	}
	l=1,r=n;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			if(b[l]!=b[r])
			{
				cnt=cnt+a[r];
			}
			a[l]=a[l]-a[r];
			r=r-1;
		}
		else if(a[l]<a[r])
		{
			if(b[l]!=b[r])
			{
				cnt=cnt+a[l];
			}
			a[r]=a[r]-a[l];
			l=l+1;
		}
		else
		{
			if(b[l]!=b[r])
			{
				cnt=cnt+a[l];
			}
			l=l+1;
			r=r-1;
		}
	}
	cout<<cnt;
	return 0;
}
