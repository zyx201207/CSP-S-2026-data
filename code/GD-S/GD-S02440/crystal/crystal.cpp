#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 500010;

int n; LL m;
LL a[N],cnt[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++) cnt[i] = cnt[i - 1] + a[i];
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		int l = 1,r = i,best = i;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int len = i - mid + 1;
			if ((LL)(i - mid + 1) * a[i] - (cnt[i] - cnt[mid - 1]) <= m){
				best = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(ans,i - best + 1);
	}
	printf("%d\n",ans);
	return 0;
}
