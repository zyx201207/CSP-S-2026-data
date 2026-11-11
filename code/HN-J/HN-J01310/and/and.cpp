#include<bits/stdc++.h>
using namespace std;
int a[2010];
struct two
{
	int len;
	int b[2010];
}c[2010];
int n,m,sum,maxn=INT_MIN;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	int ans=0,t=a[i];
    	while(t>0)
    	{
    		t/=2;
    		ans++;
		}
		c[i].len=ans;
		for(int j=ans;j>=1;j--)
		{
			c[i].b[j]=a[i]%2;
			a[i]/=2;
		}
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		    maxn=max(a[i],maxn);
	}
	    else if(m==2)
	    {
	    	for(int i=1;i<=n;i++)
            {
    	        for(int j=1;j<=n&&j!=i;j++)
    	        {
    		        int wei=0,ans=0;
    		        for(int k=c[i].len,q=c[j].len;k>=1,q>=1;k--,q--)
    		        {
    			        if(c[i].b[k]&&c[j].b[q]==1)
				            ans+=pow(2,wei);
			        	wei++;
	        		}
		        	maxn=max(maxn,ans);
	           	}
	         }
	    }
	cout<<maxn;
    return 0;
}
