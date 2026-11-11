#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],a1[10000],a2[10000],c,s,ss,l1,l2,mid,X[10000],l,r,ans;
char b[1000000],b1[10000],b2[10000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		ss+=a[i];
		X[i]=X[i-1]+a[i];
	}
	s=ss/2+1;
	for(int i=1;i<=n;i++)
	{
		c+=a[i];
		if(c>=s)
		{
			mid=i;
			break;
		}
	}
	c=0;
	for(int i=1;i<=mid;i++)
	{
		l1++;
		c+=a[i];
		if(i==mid)
		{
			if(ss%2==0)
				a1[i]=s-(c-a[i])-1,b1[i]=b[i];
			else
				a1[i]=s-(c-a[i])-1,b1[i]=b[i];
		}
		else
			a1[i]=a[i],b1[i]=b[i];
	}
	c=0;
	for(int i=n;i>=mid;i--)
	{
		l2++;
		c+=a[i];
		if(i==mid)
		{
			if(ss%2==0)
				a2[n-i+1]=X[i]-s+1,b2[n-i+1]=b[i];
			else
				a2[n-i+1]=X[i]-s,b2[n-i+1]=b[i];
		}
		else
			a2[n-i+1]=a[i],b2[n-i+1]=b[i];
	}
	int j=1;
	l=0,r=0;
	for(int i=1;i<=l1;i++)
	{
		if(l<r)
		{
			if(b1[i]!=b2[j] && l+a1[i]>=r)
				ans+=r-l;
			else if(b1[i]!=b2[j] && l+a1[i]<=r)
				ans+=a1[i];
		}
		l+=a1[i];
		while(r<l)
		{
			if(b1[i]!=b2[j] && r+a2[j]>=l)
				ans+=l-r;
			else if(b1[i]!=b2[j] && r+a2[j]<=l)
				ans+=a2[j];
			r+=a2[j++];
		}
	}
	cout<<ans;

	
	return 0;
}
