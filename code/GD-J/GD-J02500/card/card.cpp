#include<bits/stdc++.h>
using namespace std; 
long long n,m,q,w,z;
long long a[500005],b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}	
	for(int i=1;i<=n;i++)
	{
	  q=0;
	  for(int j=1;j<=n;j++)
	  {
	   if(a[i]==b[j]) 
	   {
	   	q++;
	   	w=j;
	   }
	  }	
	  if(q%2!=0) 
	  {
	  	for(int k=w;k<=n;k++)
	  	z++;
	  }
	  else if(q==0)
	  {
	  	cout<<1;
	  }
	   
	}
	cout<<m; 
	
	
	return 0;
}
