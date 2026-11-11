#include<bits/stdc++.h>
using namespace std;
int n,a[5005],m,s[5005],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int k=m;
		for(int j=1;j<=n;j++)
		{
			int l=a[i]-a[j];
			if(a[j]<=a[i]&&k>=l)
			{
				s[i]++;
				k-=(a[i]-a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,s[i]);
	}
	cout<<ans;
    return 0;	
} 
