#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005];
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
	long long t=2,maxn=0,maxnn=0;
	while(t<=n)
	{
		long long b[1000005]={0},q=1;
		for(int i=t;i<=n;i++)
		{
		b[i]=(a[i]-a[i-1])*q+b[i-1];
		q++;
	  		if(m>=b[i])
		    {
		        maxn=q;	
		    }
		    if(maxn>maxnn)
		    {
		    	maxnn=maxn;
		    }
		}
		t++;
	}
	cout<<maxnn;
	return 0;	
}
