#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	int a[1000005],b[1000005],c[1000005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
		for(int i=0;i<n;i++)
	{
        b[a[i]]++;
        if(b[a[i]]>1)
        {
        	for(int j=i;j<n;j++)
        	{
        		a[j]=0;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			c[i]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(c[a[i]]!=0)
		{
		    cout<<c[a[i]];
	    }
	}
	return 0;
} 
