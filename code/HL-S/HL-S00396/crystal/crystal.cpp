#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[500010],ans,l=1;
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(m<a[i]*(i-l+1)-(sum[i]-sum[l-1]))
		l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
 	return 0;
}
