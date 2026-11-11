#include<bits/stdc++.h>
using namespace std;
bool f[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500001],b[500001];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
	    {
	    	for(int k=1;k<a[j];k++)
	        {
	        	if(a[j]==a[k])
	        	for(int l=1;l<a[j];l++)
	            {
				    f[l]=false;
	            }
	        }
        	for(int k=1;k<=n;k++)
	        {
			    if(f[k]==true)
			    b[a[k]]++;
	        }
	    }
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i];
	}
	return 0;
}
