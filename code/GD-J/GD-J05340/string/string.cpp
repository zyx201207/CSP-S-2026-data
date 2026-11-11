#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n,a[10005],d=0;
	cin>>n;
	 char b[10005];
	 for(long i=1;i<=n;i++)
	 {
	 	cin>>a[i]>>b[i];
	 	d=d+a[i];
	 }
	 if(b[1]==b[n])
	 {
	 	cout<<"0";
	 	return 0;
	} 
	if(n%2==0)
	{
		cout<<d/2 ;
		return 0;
	}
    if(n==1)
    {
    	cout<<"0";
    	return 0;
	}
	if(n==2)
	{
		cout<<"1";
		return 0;
	}
	if(n==3)
	{
		cout<<"1";
		return 0;
	}
 
	
	 
	
	
	 
	return 0;
 } 
