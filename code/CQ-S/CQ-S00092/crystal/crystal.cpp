#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],sum[500005],s[500005],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++) d[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++) s[i]=d[i]*i;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+s[i];
	for(int i=n;i>=1;i--)
	{
		if(sum[i-1]<=m)
		{
			cout<<i<<"\n";
			return 0;
		}
	}                                                                          
	return 0;
}


