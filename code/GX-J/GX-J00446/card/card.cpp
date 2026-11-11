#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],c[500010],d[500010],s[500010];
int main()
{
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
	cin>>a[i];
	b[i]=a[i];
	c[i]=a[i];
  }
  sort(b+1,b+n+1);
  int y=0;
  d[1]=b[1];
  for(int i=2;i<=n;i++)
  {
	if(b[i]==b[i-1])
	  y++;
	else
	  d[i-y]=b[i];
  }
  int z=n,x=1;
  while(z>0)
  {
    for(int i=x;i<=n;i++)
    {
	  for(int j=x;j<i;j++)
	  {
		if(a[j]==a[i])
		{
		  for(int k=j;k<i;k++)
		    c[k]=0;
		}
	  }
    }
    for(int i=x;i<=n;i++)
    {
	  for(int j=1;j<=m;j++)
	  {
	    if(d[j]==c[i])
	      s[j]++;
	  }
    }
    for(int i=1;i<=n;i++)
    {
	  //s[i]=0;
	  c[i]=a[i];
	}
	z--;
	x++;
  }
  for(int i=1;i<=m;i++)
    cout<<s[i]<<" ";
  return 0;
}
