#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans=1,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		while(a[i+1]==a[i])
		{
			i++;
		}
		long long x=m,cnt=0;
		long long j=i-1;
		while(x>=0&&j>=0)
		{
			x-=(a[i]-a[j]);
			j--;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
