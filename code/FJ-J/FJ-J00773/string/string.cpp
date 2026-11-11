#include <bits/stdc++.h>
using namespace std;
int a,b,c,n,sum;
string s[99999999];
string d;
int main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
    cin>>b;
    for(int i=1;i<=b;i++)
    {
    	int y;
		cin>>y>>d;
		for(int i=0;i<=y-1;i++)
		{
			s[i]=d; 
		}
		sum+=y;
    }
    n=sum;
    if(n%2==0)
    {
    	for(int i=0;i<=n/2-1;i++)
    	{
    		if(s[i]==s[n-i]) a+=1;
    	}
    	cout<<a;
    }
    else if(n%2==1)
    {
    	for(int i=0;i<=(n+1)/2;i++)
    	{
    		if(s[i]==s[n-i]) a+=1;
			
    	}
    	cout<<a;
    }
	return 0;
} 
