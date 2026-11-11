#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],sum[500001],l,ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int c=1;c<=n;c++)
	{
		cin>>a[c];
	}
	sort(a+1,a+n+1);
	for(int c=1;c<=n;c++)
	{
		sum[c]=sum[c-1]+a[c];
	}
	l=1;
	for(int c=2;c<=n;c++)
	{
		while(a[c]*(c-l)-(sum[c-1]-sum[l-1])>m&&l<=c) l++;
		ans=max(ans,c-l+1);
	}
	cout<<ans;
	return 0;
}
