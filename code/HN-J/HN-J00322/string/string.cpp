#include<bits/stdc++.h> 
using namespace std;
string a[200010];
string b[200020];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,u=0,d=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(b[i]!=b[1])
		{
			u=1;
		}
	}
	if(u==0)
	{
		cout<<d;
	}
	else
	{
	    string c=b[1];
	    for(int i=2;i<=n;i++)
	    {
	    	c=c+b[i];
    	}
	    long long l=c.size();
	    for(int i=1;i<=l/2;i++)
	    {
		    if(c[i]!=c[l])
	    	{
		    	d++;
	    	}
    	}
    	cout<<d;	
   	}
	return 0;
}
