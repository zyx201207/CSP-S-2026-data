#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n;
unsigned long long m;
int s[N];
int val[N]; // ´ú¼Û
int ans;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%llu",&n,&m);
	for (int i = 1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
	}
	sort(s+1,s+n+1);
	for (int i = 1;i<=n;i++)
	{
		s[i]+=s[i-1];
	}
	for (int i = 1;i<=n;i++)
	{
		int res = 0;
		int l = 1,r = i;
		while(l<r)
		{
			int mid = (l+r)/2;
			if((i-mid)*(s[i]-s[i-1])-(s[i-1]-s[mid-1]) > m) l = mid+1;
			else r = mid;
		}
		ans = max(ans,(i-l+1));
	}
	printf("%lld",ans);
	return 0;
}
