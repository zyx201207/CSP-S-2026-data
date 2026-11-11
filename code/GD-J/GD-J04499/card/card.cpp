#include <iostream>
using namespace std;
int c[300005],d[300005] ;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],b[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
		    b[i]=a[i];
	    	if(a[i]!=0)
	    	{
	    		c[a[i]]++;
			}
	    	if(c[a[i]]==2 && a[i]!=0)
	    	{
	    		for(int h=1;h<=i;h++)
	    		{
	    			if(b[h]==a[i])
	    			{
	    				for(int k=h;k<i;k++)
	    				{
	    					b[k]==0;
						}
					}
				}
				c[a[i]]=1;
			}
	    }
	    for(int j=1;j<=m;j++)
	    {
	    	d[j]+=c[j];
	    	c[j]=0;
		}
		for(int j=1;j<=n;j++)
		{
			int l=0;
			if(b[j]!=0 && l==0)
			{
				a[j]=0;
				l=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
