#include<bits/stdc++.h>
using namespace std;
long long a[999999];
int main()
{
	long long maxv=0;
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//freopen("crystal3.in","r",stdin);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		long long cnt=0;
		long long sum=0;
		for(long long j=i;j>=1&&sum<=m;j--)
		{
			sum+=a[i]-a[j];
			cnt++;
		}
		maxv=max(maxv,cnt);
	}
	cout<<maxv;
	return 0;
}
