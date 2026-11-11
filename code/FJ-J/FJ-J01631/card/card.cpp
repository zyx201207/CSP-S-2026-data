#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	int i=0,c;
	cin>>n>>m;
	long long a[5000],d[n],sum[m];
	for(int b=0;b<n;b++)
	{
		cin>>d[n];
	}
	
	for(int s=0;s<n;s++)
	{
		i=0;
		int nn=n;
		for(int l=0;l<nn;l++)
	    {
    		a[i]=d[l]; 
		    c=0;
	    	for(int j=0;j<i;j++)
    		{
		    	if(a[i]==a[j])
	    		{
				    for(int k=0;k<=i;i++)
			    	{
				    	a[k]=0;
			    	}
				    i=0;
			    }
		    }
	       	i++;
    	}
    	for(int j=0;j<i;j++)
		{
			if(a[j]!=0)
			sum[a[j]-1]++;
		}
		for(int j=0;j<nn;j++)
		{
			d[j]=d[j+1];
		}
		nn--;
		
	}
	for(int j=0;j<m;j++)
	{
		cout<<sum[j]<<" ";
	}
 }
