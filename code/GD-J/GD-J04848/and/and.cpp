#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
  int num,boo;
};
int a[200010];
int b[200010];
int a2[35];
int ans=2048*2048;
int f;
int g=n;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
   	  cin>>a[i];
   }
   a2[0]=1;
   for(int i=1;i<=31;i++)
   {
   	  a2[i]=a2[i-1]*2;
   	  
   }
   sort(a+1,a+1+n);
   for(int i=n;i>=1;i--)
   {
   	for(int j=1;j<=31;j++)
   	{
   		if(a[i]==a2[j]-1)
   		{
   		   b[i]=1;	
   		  
   	    }
	}
	}
   
   g=n;
   while(g!=0)
   {
   	if(b[g]==0&&f==0)
   	{
   		ans=a[g];
   		f=1;
   		m--;
	}
	else if(b[g]==0)
	{
		ans = ans & a[g];
		m--;
	}
	g--;
   }
   g=n;
   while(m!=0)
   {
   	if(b[g]==1&&f==0)
   	{
   		ans=a[g];
   		f=1;
   		m--;
	}
	else if(b[g]==1)
	{
		ans = ans & a[g];
		m--;
	}
	g--;
   }
   cout<<ans;
}
