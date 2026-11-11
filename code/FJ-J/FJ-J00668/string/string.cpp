#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n,x=0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		cin>>a[i]>>a[j];	
    		if(a[i]==1)
    		{
    			x=x+0;
			}
    	    if(a[1]%2==0)
    	    {
    	    	x=x+a[i]/2;
			}
			else if(a[i]%2==1)
			{
				x=x+a[i]/2;
			}
			if(a[j]==a[j])
			{
				cout<<0;
				return 0;
			}
		}
		
	}
	cout<<x;
	return 0;
}
