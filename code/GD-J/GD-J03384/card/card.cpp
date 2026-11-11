#include <iostream> 
#include <algorithm>
using namespace std;
#define int long long
int n,m,a[500008],c[500008];
int all[500008];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		bool b[500008]={};
		int sum=1;
		for(int j=i;j<=n;j++)
		{
		    if(b[a[j]]==0)	
		    {
		    	c[sum]=a[j];
		    	b[a[j]]=1;
		    	sum++;
			}
			else
			{
				for(int s=1;s<=m;s++)
				{
					b[s]=0;
				}
				for(int s=1;s<sum;s++)
				{
					b[c[s]]=1;
					if(c[s]==a[j])
					{
						sum=s+1;
						break;
					}
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]==1)
			{
				all[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<all[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
}
