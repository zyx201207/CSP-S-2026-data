#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(m==1)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		long long ans=a[1];
		for(int i=2;i<=n;i++)
		ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long x=(a[i]&a[j]);
				ans=max(ans,x);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

