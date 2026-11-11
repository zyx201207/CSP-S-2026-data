#include<bits/stdc++.h>
using namespace std;
long long n,d,x[100005],zong=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int b,z;
	cin>>b>>z;
    for (int o=1;o<=z;++o)
    {
    	cin>>n>>d;
    	for (int i=1;i<=n;i++)
    	{
    	    cin>>x[i];	
		}
		for (int i=1;i<=n;i++)
    	{
    	    for (int j=2;j<=n;j++)
    	    {
    	    	int shu=0;
    	    	for (int k=1;k<=d;k++)
    	    	{
    	    		if (x[i]+k<x[j] && x[j]-(x[i]+k)<=d)
    	    		{
    	    		    shu++;
					}	
				}
				if (shu==2)
				zong++;
			}
		}
		cout<<zong<<endl;
		zong=0;
		
	}
	return 0;
}
