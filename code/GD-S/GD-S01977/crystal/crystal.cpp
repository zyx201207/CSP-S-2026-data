#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],s=1,r,l;
int check(int x)
{
	int p=1,t=m,z=x;
	while(a[z+1]==a[z])
	{
		z++;
		p++;
	}
	for(int i=x-1;i>=1;i--)
	{
		if(t>a[x]-a[i])
		{
		    t=t-(a[x]-a[i]);
			p++;
		}
		else
		{
		    if(t==(a[x]-a[i]))
		    {
		    	p++;
		    	if(p>s) s=p;
		    	return 2;
			}
			if(p>s) s=p;
			return 1;
		}
	}
	if(p>s) s=p;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid)==1) r=mid-1;
		else if(check(mid)==0) l=mid;
		else if(check(mid)==2)
		{
			cout<<s;
			return 0;
		}
	}
	cout<<s;
	return 0;
}
