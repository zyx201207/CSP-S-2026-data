#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long x;
	char y;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,n;
	cin>>n;
	a[0].x=0;
	a[0].y='.';
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		if(a[i].y==a[i-1].y)
		{
			a[i-1].x=a[i-1].x+a[i].x;
			i--;
			n--;
		}
	}
	long long l,r,ans=0;
	for(l=1,r=n;l<r;l++)
	{
		while(a[l].x>0&&l<r)
		{
			if(a[l].y==a[r].y)
			{
				if(a[l].x>=a[r].x)
				{
					a[l].x=a[l].x-a[r].x;
					a[r].x=0;
					r--;
				}
				else if(a[l].x<a[r].x)
				{
					a[r].x=a[r].x-a[l].x;
					a[l].x=0;
				}
			}
			else
			{
				ans=ans+min(a[l].x,a[r].x);
				a[r].x=a[r].x-a[l].x;
				if(a[r].x<=0)
				{
					a[l].x=-a[r].x;
					a[r].x=0;
					r--;
				}
				else
					a[l].x=0;
			}
		}
	}
	cout<<ans;
}
