#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0,lans=0,f=0;
map<long long,long long> a;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(m==1)
        {
           ans=max(ans,a[i]);
		   f=1;
	    }
	}
	if(f==1)
	{
		 cout<<ans;	
        return 0;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
		   for(int j=i+1;j<=n;j++)
		   {
		   	  lans=(a[i]&a[j]);
		   	  if(lans>ans)
			  {
			  	ans=lans;
			  } 
		   }	
		}
		cout<<ans;
		return 0;
	}
    for(int i=1;i<=n;i++)
    {
    	ans=max(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
