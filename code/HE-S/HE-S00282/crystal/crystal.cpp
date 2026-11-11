#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	int n,m; 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=1;
	for(int i=n;i>=1;i--) 
	{
		for(int i=m;i>=1;i--) 
		{
			if(a[i]+1==a[i+1])
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
