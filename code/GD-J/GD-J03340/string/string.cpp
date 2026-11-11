#include <bits/stdc++.h>
using namespace std;


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

    long long a=0,s=0,x=0,y=0; 
    int n=0;
    string b,c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a>>b;
    	for(int j=1;j<=a;j++)
    	{
    		c+=b;
		}
	}
	
	x=c.size();
	y=x-1;
    for(int k=0;k<x/2;k++)
    {
    	if(c[k]!=c[k+y])
    	{
    		s++;
		}
		y=y-2;
	}
	cout<<s;
    return 0;	
}
