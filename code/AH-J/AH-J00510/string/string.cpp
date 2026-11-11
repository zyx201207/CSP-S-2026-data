#include <bits/stdc++.h>
using namespace std;
int a[200005],n,l,r;
long long s,x,y;
char o[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>o[i];
	}
	l=1;
	r=n;
	x=a[1];
	y=a[n];
	while(l<=r)
	{
		if(x<y)
		{
			if(o[l]!=o[r])
			{
				s=s+x;
				y=y-x;
				x=0;
			}
			else
			{
				y=y-x;
				x=0;
			}
			l++;
			x=x+a[l];
		}
		else
		{
			if(o[l]!=o[r])
			{
				s=s+y;
				x=x-y;
				y=0;
			}
			else
			{
				x=x-y;
				y=0;
			}
			r--;
			y=y+a[r];
		}
	}
	cout<<s;
}
