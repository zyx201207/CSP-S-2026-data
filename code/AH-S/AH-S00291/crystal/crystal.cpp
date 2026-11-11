#include<bits/stdc++.h>
using namespace std;
long long a[500005],f[500005],k[500005],n,m,l,r,s,o,c;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		f[i]=a[i]-a[i-1];
		k[i]=k[i-1]+f[i];
	}
	l=1;
	r=1;
	o=0;
	c=1;
	while(l<=r&&l>=1&&r<=n)
	{
		r++;
		o=o+f[r]*(r-l);
		c++;
		if(o>m)
		{
			while(o>m)
			{
				o=o-(a[r]-a[l]);
				c--;
				l++;
			}
		}
		s=max(s,c);
	}
	cout<<s;
}
