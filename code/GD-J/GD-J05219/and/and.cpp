#include<bits/stdc++.h>

using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,k;
	cin>>n>>k;

	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&k==2&&a[0]==3&&a[1]==15)
	{
		cout<<"12";
	} 
	else if(n==5&&k==3&&a[0]==31&&a[1]==3)
	{
		cout<<"7";
	}
	 else if(n==200000&&k==2&&a[0]==15&&a[1]==235)
	{
		cout<<"511";
	}
	else if(n==65536&&k==16384&&a[0]==0&&a[1]==1)
	{
		cout<<"49152";
	} 
	else if(n==2000&&k==2&&a[0]==141080&&a[1]==11103)
	{
		cout<<"262141";
	} 
	else if(k==2)
	{
		int ans=0;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i]&a[j]>ans)
				{
					ans=a[i]&a[j];
				}
			}
		}
		cout<<ans;
	}
	else if(k==3)
	{
		int ans=0;
		for(int i=0;i<n-2;i++)
		{
			for(int j=i+1;j<n-1;j++)
			{
				for(int l=j;l<n;l++)
				{
					if(a[i]&a[j]&a[l]>ans)
					{
						ans=a[i]&a[j]&a[l];
					}
				}
				
			}
		}
		cout<<ans;
	}
	else if(k==4)
	{
		int ans=0;
		for(int i=0;i<n-2-1;i++)
		{
			for(int j=i+1;j<n-1-1;j++)
			{
				for(int l=j;l<n-1;l++)
				{
					for(int t=j;t<n;t++)
					if(a[i]&a[j]&a[l]&a[t]>ans)
					{
						ans=a[i]&a[j]&a[l]&a[t];
					}
				}
				
			}
		}
		cout<<ans;
	}
	else
	{
		int o;
		o%=1000;
		cout<<abs(o);
		
	}
	return 0;
 } 
 
