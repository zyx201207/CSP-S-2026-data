#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[100001],b[100001],c[100001],ans=0;
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
    for(int j=i;j<=n;j++)
    {
		for(int x=j;x<=n;x++)
		{
		  for(int y=x+1;y<=n;y++)
		  {
		    if(b[x]==b[y]&&b[x]!=0)
		    {
		      for(int z=x+1;z<=y;z++)
		      {
				b[z]=0;
		      }
		    }
		  }
		}
	} 
	for(int g=1;g<=m;g++)
      {
	    for(int h=i;h<=n;h++)
	    {
		  if(b[h]==g)
		  c[g]++;
        }
      }
      for(int t=i;t<=n;t++)
        b[t]=a[t];
  } 
  for(int i=1;i<=m;i++)
  {
    cout<<c[i]<<" ";
  }
  return 0;
}
