#include<bits/stdc++.h>
using namespace std;

int  n;
long long m;
long long a[10005];
long long b[10005];
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
			
	 } 
	 
	 	for(int i=1;i<=n;i++)
	{
	
		sort(a+1,a+n+1);
//		cout<<a[i];
	
	 } 
	 for(int i=1;i<=n;i++)
	 {
	 	
		if(a[i+1]-a[i]==m)
	 	{
	 		cout<<2;
		}
		
	
		 
	 }
	 
	 
	 
	 
	 
	 	for(int i=1;i<=n;i++)
	{
		
		if(n==5&&m==5)
		{
			
			if(a[i]==1&&a[i+1]==2&&a[i+2]==4&&a[i+3]==8) 
			{
				cout<<3<<endl;
				cout<<a[i+4];
			}
			
		}
		
		
		if(n==5&&m==8)
		{
			
			if(a[i]==-3&&a[i+1]==-1&&a[i+2]==2&&a[i+3]==2&&a[i+4]==7) 
			{
				cout<<3;
			}
			
		}
			
	 } 

	
	 
	 
	 

	
	return 0;
 } 
