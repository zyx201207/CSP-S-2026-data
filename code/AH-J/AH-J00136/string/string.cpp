#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100005],sum=0,num=0;
	string x,y,s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>x[i];
		for(int j=0;j<a[i];j++)
		{
			y[j]=x[i];
		}
		num+=a[i];
	}
	if(num%2==0)
	{
		int t=num/2;
		for(int i=0;i<t;i++)
	    {
		    s[i]=y[i];
	    }
	    for(int i=num-1;i>=t;i--)
	    {
	    	int w=x[i],r=s[num-i-1];
	    	if(w==r)
	    	{
	    		sum++;
			}
			else
			{
				continue;
			}
		}
	}
	else if(num%2!=0)
	{
		int t=(num/2)-1;
		for(int i=0;i<t;i++)
	    {
		    s[i]=y[i];
	    }
	    for(int i=num-1;i>=t+2;i--)
	    {
	    	int w=x[i],r=s[num-i-1];
	    	if(w==r)
	    	{
	    		sum++;
			}
			else
			{
				continue;
			}
		}
	}
	cout<<sum;
}
