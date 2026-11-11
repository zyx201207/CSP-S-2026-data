#include<bits/stdc++.h> 
using namespace std;
int a[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,f=1,x=0;
	cin>>n>>m;
	cin>>a[1]>>a[2];
	for(int i=3;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
		  f=0;
	}
	sort(a+1,a+n+1);
	s[1]=0;
	for(int i=2;i<=n;i++)
	{
		s[i]=a[i]-a[i-1]+s[i-1];
		x+=s[i]-s[1];
		if(f&&x>m)
		{
			cout<<i-1;
			return 0;
		}
	}
	int l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		x+=s[n]-s[i];
	}
	while(l<=r)
	{
		if(x<=m)
		  break;
		else
		  if((s[r]-s[r-1])*(r-l)>=s[l+1]-s[l])
		    {
		    	x-=(s[r]-s[r-1])*(r-l);
		    	r--;
			}
		  else
		    {
		    	x-=s[l+1]-s[l];
		    	l++;
			}
	}
	cout<<r-l+1;
	return 0;
}
