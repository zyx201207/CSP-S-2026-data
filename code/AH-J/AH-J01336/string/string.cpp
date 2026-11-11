#include<bits/stdc++.h>
using namespace std;
long long n,x,a[200005],len,l,r,cnt,ans;
char y,c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if (y==c[len])
		{
			a[len]+=x;
		}
		else
		{
			len++;
			a[len]=x;
			c[len]=y;
		}
	}
	l=1,r=len;
	while(l<r)
	{
		if (a[l]>a[r])
		{
			if (c[l]!=c[r])
			{
				ans+=a[r];
			} 
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
		else if (a[r]>a[l])
		{
			if (c[l]!=c[r])
			{
				ans+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else
		{
			if (c[l]!=c[r])
			{
				ans+=a[l];
			}
			a[r]=a[l]=0;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
