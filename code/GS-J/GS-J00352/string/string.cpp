#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,sum=0;
	string a,b;
	cin>>n,;
	for(int k=0;k<n;k++)
	{
		cin>>a;
		for(int i=0;i<n;i++)
	    {
    		for(int j=0;j<a[i+i+1];j++)
    		{
			b[j]=a[i+i+2];
	    	}
    	}
    	for(int i=0;i<b.size()/2;i++)
    	{
    		if(b[i]!=b[b.size()-i-1])
    		{
    			b[b.size()-i-1]=b[i];
    			sum++;
	    	}
    	}
	}
	cout<<sum;
}
