#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int x,y[n],z;
	z=0;
	for(int i=0;i<n;i++)
	{
	    x=m;
	    y[i]=z;
		for(int j=0;j<i;j++)
	    {
	    	m-=a[i]-a[i-j];
	    	if(m<=0)
	    	{
	    		break;
	    	}
	    	y[i]++;
	    	
	    	
		
		}

		if(y[i]>=z)
		{
			z=y[i];
		}
		
	}	
	cout<<z-1;

	return 0;
}
