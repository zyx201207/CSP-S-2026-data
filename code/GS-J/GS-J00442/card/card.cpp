#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],k[1005],ans[1005];
int main()
{
   //freopen("card.in","r",stdin)
   //freopen("card.out","w",stdout)
   cin>>n>>m;
   for(int i=0;i<=n;i++)
   {
   	cin>>a[i];
   }
	for(int i=n;i>=0;i--)
	{
	  k[i]=a[i];
	  for(int j=0;j<=i;j++)
	  {
	  	if(a[i]==k[j])
	  	{
	  		if(i>j)
	  		{
	  		for(int x=j;x<=i;x++)
			  {
			  	a[x]=0;
			  }	
			}
			else
			{
				for(int y=i;y<=j;y++)
				{
					a[y]=0;
				}
			}
	  		for(int s=m-j;s<=n;s++)
	  		{
	  		a[s]=a[i];
			  for(int h=1;h<=s;h++)
			  {
			     if(a[s]==h)
			     {
			     	ans[s]++;
				 }
			  }	
			}
		}
		else
		{
			continue;
		}
	  }
	}
	for(int i=1;i<=n;i++)
	{
	cout<<ans[i]<<" ";	
	}
	return 0;	
}  
