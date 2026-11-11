#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[1000005];
char b[1000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0,q=0,s=0,t=0;
    cin>>n;
    for(int i=0;i<n;i++)
	{
	cin>>a[i]>>b[i];
	sum=sum+a[i];
}
n--;
    sum=sum/2;
    while(q<n)
    {
    	if(a[q]>a[n])
    	{
    		if(b[q]==b[n])
    		{
    			if(t+a[n]>=sum)
    			{
    				cout<<s;
    				return 0;
				}
    			a[q]=a[q]-a[n];
    			t=t+a[n];
    			n--;
			}
    		else
    		{
    			if(t+a[n]>=sum)
    			{
    				cout<<s+sum-t;
    				return 0;
				}
    			a[q]=a[q]-a[n];
    			t=t+a[n];
    			s=s+a[n];
    			n--;
			}
		}
    	else if(a[q]<a[n])
    	{
    		if(b[q]==b[n])
    		{
    			if(t+a[q]>=sum)
    			{
    				cout<<s;
    				return 0;
				}
    			t=t+a[q];
    			a[n]=a[n]-a[q];
    			q++;
			}
    		else
    		{
    			if(t+a[q]>=sum)
    			{
    				cout<<s+sum-t;
    				return 0;
				}
    			t=t+a[q];
    			a[n]=a[n]-a[q];
    			s=s+a[q];
    			q++;
			}
		}
    	else
    	{
    		if(b[q]==b[n])
    		{
    			if(t+a[q]>=sum)
    			{
    				cout<<s;
    				return 0;
				}
    			t=t+a[q];
    			n--;
    			q++;
			}
			else
			{
				if(t+a[q]>=sum)
    			{
    				cout<<s+sum-t;
    				return 0;
				}
    			t=t+a[q];
				s=s+a[q];
				n--;
				q++;
			}
		}
	}
    cout<<s;
    
    return 0;
}

