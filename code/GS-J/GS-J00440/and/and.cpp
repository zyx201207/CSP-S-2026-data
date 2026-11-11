#include<bits/stdc++.h>
using namespace std;
long long int n,m,r=-11,l,ans=-11,a[100010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];r=max(r,a[i]);
	}
	if(m==1)
	{
		cout<<r;
		return 0;
	}if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,a[i]&a[j]);
		}	
		}cout<<ans;
	}if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=(ans&a[i]);cout<<ans;
		}
		
	}
	return 0;
 } 
