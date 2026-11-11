#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long b[600006];
long long ans1,ans2,cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
			cin>>b[i];
	}
	sort(b+1,b+n+1);
	for(long long i=1;i<=n;i++)
	{
		cnt=0;
		ans1=0;
		for(long long j=1;j<=i;j++)
		{
			long long  k=abs(b[i]-b[j]);
			if(k+cnt<=m)
			{
				cnt+=k;
				ans1++;

			}
			ans2=max(ans1,ans2);
		}
	}
	cout<<ans2;
	return 0;
}
