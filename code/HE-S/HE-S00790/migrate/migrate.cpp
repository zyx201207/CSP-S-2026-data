#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000010];
int a[2000010];
int s=0;
int h=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	for(int i=1;i<=n;i++)	
	{
		cin>>x[i];
		for(int j=1;j<=x[1];i++)
		{
			cin>>a[j];
		    if(a[n]-a[j]==(a[n]-a[j+1])+(a[n]-a[j+2])||a[j]!=a[j-1]||x[i]-a[j]<=d)
		    {
			    s+=1;
		    }
		    else if(c==0)
		    {
		    	return 0;
			}
	 	    else
		    {
			    cout<<0<<endl;
			    return 0;
		    }
	    }
	 } 
	if(s>=2||s/2==0)
	{
		cout<<s/2<<endl;
	 } 
	 
	return 0;
 } 
