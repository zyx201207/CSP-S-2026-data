#include<bits/stdc++.h>
using namespace std;
int a[200005],p[200005],q[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0;
	cin>>n>>m;
	bool b=true,c=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i-1)
		{
			b=false;
		}
		if(a[i]!=pow(2,i)-1)
		{
			c=false;
		}
		int x=a[i],j=0;
		while(x!=0)
		{
			if(x%=2)
			{
				if(p[j]!=0)
				{
					q[j]=pow(2,j);
				}
				else
				{
					p[j]=i;
				}
				j++;
			}
			x/=2;
		}
		ma=max(ma,j);
	}
	if(b)
	{
		if(n-1%2)
		{
			cout<<pow(2,n/2)<<endl;
		}
		else
		{
			cout<<pow(2,n/2-1)<<endl;
		}
	}
	else if(c)
	{
		cout<<n/2-1<<endl;
	}
	else
	{
		int ans=0;
		for(int i=1;i<=ma;i++)
		{
			 ans+=p[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
