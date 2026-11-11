#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,m,a[50000001],ff=0,l=0,sum=0,q[50000001],minl=0x3fffffff,t=1,w=0;
int main()
{
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(0);
		cin>>n>>m;
		w=m;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		
		sort(a+1,a+n+1);
		
		for(int i=1;i<=n;i++)
		{
		q[i]=q[i-1]+a[i];
		if(i==2)
		{
		l=a[i]-a[i-1];
		if(l!=0)
		minl=min(l,minl);
		}
		if(i>2&&ff==0)
		 if(a[i]-a[i-1]!=l)
		  ff=1;
	    }
		if(ff==0)
		{
		long long ans=0;
		 for(int i=1;i<=n;i++)
		 	{
			ans+=i*l;
			if(ans>m)
			{
			sum=i;
			break;
			}
			if(i==n)
			sum=i;
			}
		cout<<sum;
		return 0;
		}
		for(int i=n;i>=1;i--)
		{
		long long ans=0;
		m=w;
		 for(int j=i;j>=1;j--)
		  {
			m-=a[i]-a[j];
			if(m>=0)
			  ans++;
			  else
			  {
			  sum=max(ans,sum);
			  break;
			}
			if(j==1)
			sum=max(ans,sum);
			}
		}
		cout<<sum;
		
		return 0;
}
