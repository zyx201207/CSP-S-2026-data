#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e5+5;

int a[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);

	sort(a+1,a+n+1);

	int ans=0, l=1, sum=0;
	for(int i=1;i<=n;i++)
	{
		sum += a[i];
		while(a[i]*(i-l+1)-sum>m)
			sum -= a[l], l++;
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}