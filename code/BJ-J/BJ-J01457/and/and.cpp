#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
  }
	if(n<=2000)
	{
		if(m==1)
		{
			sort(a+1,a+n+1,greater<int>());
			cout<<a[1];
	  }
	  else if(m==n)
	  {
	    long long ans=a[1];
		  for(int i=2;i<=n;i++)
		  {
			  ans&=a[i];
		  }
		  cout<<ans;
	  }
	  else
	  {
		  long long ans=-1;
		  for(int i=1;i<=n;i++)
		  {
			  for(int j=i;j<=n;j++)
			  {
				  if((a[i]&a[j])>ans) ans=a[i]&a[j];
			  }
		  }
		  cout<<ans;
	  }
  }
  else
  {
	  sort(a+1,a+n+1,greater<int>());
	  long long ans=a[1];
	  for(int i=2;i<=m;i++)
	  {
		  ans&=a[i];
	  }
	  cout<<ans;
	}
	return 0;
}