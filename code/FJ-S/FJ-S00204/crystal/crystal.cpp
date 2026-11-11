#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],b[500005],ans=-1e9;
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
    for(int i=1;i<=n;i++)
    {
    	b[i]=b[i-1]+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(1ll*a[i]*(i-1)-b[i-1]<=m)
		{
			ans=max(ans,1ll*i);
		}
		else
		{
			if(n<=5000)
			{
		    	for(int j=2;j<=i;j++)
		    	{
			    	if(1ll*a[i]*(i-j)-(b[i-1]-b[j-1])<=m)
			    	{
					    ans=max(ans,1ll*i-j+1);
					    break;
				    }
	       	    }
	       	}
	        else{
	    		int l=1,r=i-1;
	     		while(l<i-1&&1ll*(a[i]*(i-l))-(b[i-1]-b[l-1])>m)
		    	{
		    		int mid=(l+r)>>1;
		     		if(1ll*(a[i]*(i-l))-(b[i-1]-b[mid-1])>m)
		    		{
			    		l=mid+1;
		    		}
		    	}
		    	while(l>1&&1ll*(a[i]*(i-l))-(b[i-1]-b[l-1])<=m)
		    	{
			    	l--;
			    }
			    ans=max(ans,1ll*i-l+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
