#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int ro=1,ee=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2) ee=a[i]-a[i-1];
		if(i>=2)
		if((a[i]-a[i-1])!=ee)ro=0;
	}
	if(ro==1)
	{
		long long an=0;
    	for(long long j=n;j>=1;j--)
    	{
    		
    		an+=a[n]-a[j];
    		if(an>m)
    		{
    			ans=max(ans,n-j);
    			break;
			}
			if(j==1)
			{
				ans=max(ans,n);
			}
		}
	}
	else
	{
		sort(a+1,a+1+n);
	    for(long long i=1;i<=n;i++)
	    {
	    	long long an=0;
	    	for(long long j=i-1;j>=1;j--)
	    	{
	    		
	    		an+=a[i]-a[j];
	    		if(an>m)
	    		{
	    			ans=max(ans,i-j);
	    			break;
				}
				if(j==1)
				{
					ans=max(ans,i);
				}
			}
		}
	}

	cout<<ans;
	return 0;
}
