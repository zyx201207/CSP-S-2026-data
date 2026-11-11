#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
long long  a[MAXN];
long long b[MAXN];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=0,sum,cnt=-1;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
	{
	    sum=-1;
		for(int j=i;j<=n;j++)
		{
			if(ans!=a[j])
	    	{
	    		sum=max(sum,(a[i])&(a[j]));
	    		ans=a[j];
	    	}
	    	else if(ans==a[j]&&x==0)
	    	{
	    		sum=max(sum,(a[i])&(a[j]));
	    		ans=a[j];
	    		x++;
	    	}
	    	else continue;
		}
		b[i]=sum;
	}
	for(int i=1;i<=n;i++)
	{
		cnt=max(cnt,b[i]);
 	}	
    	 cout<<cnt;
    	 return 0;
	}
    else if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	else if(m==n)
	{
		long long x=a[1];
		for(int i=1;i<=n;i++)
		{
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
    else
    {
    	for(int i=1;i<=n;i++)
	{
	    sum=-1;
		for(int j=i;j<=n;j++)
		{
			if(ans!=a[j])
	    	{
	    		sum=max(sum,(a[i])&(a[j]));
	    		ans=a[j];
	    	}
	    	else continue;
		}
		b[i]=sum;
	}
	for(int i=1;i<=n;i++)
	{
		cnt=max(cnt,b[i]);
 	}	
    	 cout<<cnt;
    	 return 0;
    }
}
