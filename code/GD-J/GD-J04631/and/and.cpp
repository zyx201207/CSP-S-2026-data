#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[30][200010],ss[200010],sss,dy,b[30],zd,s[200010][30]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	  int c;	
	  cin>>c;
	  int ws=0;
	  while(c)
	  {
	   ws++;
	   zd=max(zd,ws);
	   if(c%2==1)
	   {
	   	b[ws]++;
	   a[ws][b[ws]]=i;
	   s[i][ws]=1;
	   }
	   	c/=2;
	  }
	}
	int zgw=0;
	 for(int i=zd;i>=1;i--)
	  if(b[i]>=m)
	  {
	  	zgw=i;
	  	break;
	  }	
	  dy=b[zgw]-m;
	  if(dy>0)
	  for(int i=zgw-1;i>=1;i--)
	    {
	    	int zs=0;
	    	sss=0;
	      for(int j=1;j<=b[zgw];j++)
	      {
	      	if(s[a[zgw][j]][i]&&a[zgw][j]!=0)
	      	zs++;
	      	else if(a[zgw][j]!=0)
	      	{
	      		sss++;
	      		ss[sss]=j;
			}
		  }
	      if(zs>=m&&sss>0)
	      {
	      	for(int j=1;j<=sss;j++)
	      	a[zgw][ss[sss]]=0;
	      	dy-=sss;
		  }
		  if(dy==0)
		  break;
		}
		long long eb=1;
		for(int i=1;i<=zgw;i++)
		{
			int f1=0;
			for(int j=1;j<=b[zgw];j++)
		  {
		  	if(a[zgw][j])
		  	  if(!s[a[zgw][j]][i])
		  	  f1=1;
		  }
		  if(f1==0)
		  ans+=eb;
		  eb*=2;
		}
		 cout<<ans; 
	return 0;
 } 
