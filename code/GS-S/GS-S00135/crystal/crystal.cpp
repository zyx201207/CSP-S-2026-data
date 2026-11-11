#include <iostream>
#include <algorithm>
typedef long long ll;
const int N = 5e5 + 5;
ll a[N],sum[N];
int main(void)
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n = 0;
	ll m = 0;
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	std::sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for(int i = 1,j = 1;i <= n;i++)
	{
		while(j <= i && (ll)(i - j + 1) * a[i] - (sum[i] - sum[j - 1]) > m) j++;
		if(i - j + 1 > ans) ans = i - j + 1;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
