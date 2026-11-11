#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int maxn= 5e5+10;
int n,m,a[maxn],dp[maxn],maxx;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++) dp[i] = dp[i-1]+a[i];
	for(int i = 2;i<=n;i++)
	{
		int s = dp[i-1] - dp[i-maxx-2];
		int k = (maxx+1)*a[i] - s;
		if(k<=m) maxx++;
	}
	maxx++;
	cout << maxx << " ";
	return 0;
}
