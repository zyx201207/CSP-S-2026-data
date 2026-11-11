#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+20;
int x[maxn],x_1[maxn],x_2[maxn],n,d;
int find1(int m)
{
	int l=1,r=n;
	while(l<=r)
    {
      int mid=l+(r-l)/2;
      if(x[mid]<=m) l=mid+1;
      else r=mid-1;
	}	
    return m;
}
int find2(int m)
{
    int l=1,r=n;
	while(l<=r)
    {
      int mid=l+(r-l)/2;
      if(x[mid]>=m) r=mid-1;
      else l=mid+1;
	}	
	return l;
}
 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)
	{
	  cin>>n>>d;int ans=0;
	  for(int i=1;i<=n;i++) cin>>x[i]; 
	  for(int i=1;i<=n;i++)
	    x_1[i]=find2(x[i]-d),x_2[i]=find1(x[i]+d);
	  for(int i=1;i<=n;i++)
	  {
	  	int j=x_2[i];
	  	while(j<=n)
	  	{
	  	  if(x_2[i]-x_1[j]==1||(x_2[i]-x_1[j]==2&&x_1[j]==i)) ans++;
	  	  j=x_2[j];
		}
		}
	  cout<<ans<<endl;  
	}
	return 0;
}
//if(x_2[i]-x_1[x_2[i]]==1||(x_2[i]-x_1[x_2[i]]==2&&x_1[x_2[i]]==i)) ans++;
