#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0,flag=0;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%lld %c",&a[i],&b[i]);
	int l=1,ly=a[1],r=n,ry=a[n];
	while(l<r)
	{
		if(b[l]!=b[r])
		{
			if(ly>=ry)
			{
				ly-=ry;
				ans+=ry;
				if(r-1==l)
				{
					cout<<ans;
					return 0;
				}
				else
				{
					r--;
					ry=a[r];	
				}
			}
			else
			{
				ry-=ly;
				ans+=ly;
				if(r==l+1)
				{
					cout<<ans;
					return 0;
				}
				else
				{
					l++;
					ly=a[l];
				}
			}
		}
		else
		{
			if(ly>=ry)
			{
				ly-=ry;
				if(r-1==l)
				{
					cout<<ans;
					return 0;
				}
				else
				{
					r--;
					ry=a[r];
				}
			}
			else
			{
				ry-=ly;
				if(r==l+1)
				{
					cout<<ans;
					return 0;
				}
				else
				{
					l++;
					ly=a[l];
				}
			}
		}
		if(ry==0)
		{
			if(r-1==l)
			{
				cout<<ans;
				return 0;
			}
			else
			{
				r--;
				ry=a[r];
			}
		}
		if(ly==0)
		{
			if(l+1==r)
			{
				cout<<ans;
				return 0;
			}
			else
			{
				l++;
				ly=a[l];
			}
		}
	}
	return 0;
}
