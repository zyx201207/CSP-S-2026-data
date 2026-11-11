#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,pos=1,ans=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(a[i]*(i-pos+1)-sum[i]+sum[pos-1]>m)
		{
			pos++;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}
