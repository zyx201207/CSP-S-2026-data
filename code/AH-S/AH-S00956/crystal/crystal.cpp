#include <bits/stdc++.h>
using namespace std;
const int L=5e5+7;
long long a[L]={0};
long long b[L]={0};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long r=0,sum=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		while(sum<=m&&r<=n)
		{
			r++;
			if(r==n+1) break;
			long long w=(r-i)*1ll*(a[r]-a[r-1]);
			sum+=w;
		}
		ans=max(ans,r-i);
		sum-=a[r]-a[i];
	}
	cout<<ans<<endl;
	return 0;
}


