#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int mtime[500005],ntime[5005][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) 
	{
		cin>>mtime[i];
	}
	int num;
	int t;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		for(int j=1;j<=num;j++)
		{
		 cin>>t>>ntime[i][t];	
		}
	}
	int a,b;
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		int ans=0;
	     int sum=0;
		ans+=mtime[a]+mtime[b];
			for(int k=1;k<=n;k++)
		    {
			    sum+=ntime[k][a]+ntime[k][b];
		    	for(int g=k+1;g<=n;g++)
		    	{
		    		for(int j=a+1;j<b;j++)
		    		{
		    			if(ntime[k][j]>0&&ntime[g][j]>0)
	                     sum+=ntime[k][j]+ntime[g][j];
		    		}
		    	}
		    }
		cout<<ans+sum<<endl;
	}
	return 0;
}
