#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans;
long long x[200005],g[1005][1005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
	    for(int i=1;i<=n;i++)
	    {
		    cin>>x[i];
	    }
	    for(int i=1;i<=n;i++)
	    {
	    	for(int j=1;j<=n;j++)
	    	{
	    		if(x[i]!=x[j]&&x[i]-x[j]<=0) g[i][j]=x[i]-x[j];
	    		if(x[i]!=x[j]&&x[j]-x[i]>0) g[i][j]=x[j]-x[i];
	    		g[j][i]=g[i][j];
			}
		}
		for(int i=1;i<=n;i++)
	    {
	    	for(int j=1;j<=n;j++)
	    	{
	    		//cout<<i<<" "<<x[i]<<"||"<<j<<" "<<x[j]<<"||"<<g[i][j]<<endl;
	    		//cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
	    		if(g[i][j]>=d&&n!=2)
	    		{
	    			//cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
	    			if(j>i&&j-i==3)
	    			{
	    				//cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
	    				if(x[j]-x[i]<=d)
	    				{
						    //cout<<i<<" "<<j<<" "<<g[i][j]<<endl;	
	    				    if(g[i][j]<=2*d&&g[i][j]>d)
	    				    {
	    					    //cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
	    					    ans++;
						    }
						}
					}
				}
				else if(n==2)
				{
					ans=2;
				}
			}
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
