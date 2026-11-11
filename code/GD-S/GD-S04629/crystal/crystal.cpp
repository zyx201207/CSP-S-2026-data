#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b,sum=1;
	cin>>a>>b;
	int c[a];
	for(int i=1;i<=a;i++)
	{
		int sm=0,x[i-1];
		cin>>c[i];
		for(int j=1;j<=i-2;j++)
    	{
    		x[j]=c[i]-c[j];
			sm+=c[i]-c[j];
        }
        if(b>sm-max(x[i-1],x[1])-max(x[i-2],x[2]))
        {
           sum=i-2;
		}
		if(b>sm-max(max(x[i-2],x[2]),max(x[i-1],x[1])))
        {
           sum=i-1;
		}
        if(b>sm);
        {
        	sum=i;
		}
	}
	cout<<sum;
	return 0;
} 
