#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define TIII tuple<int,int,int>
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define il inline
#define rg register
#define fi first
#define se second
#define MAXN 200005
using namespace std;
int n,m,a[MAXN],ans = 0,dp[2005][2005],maxnai,sum[MAXN];
const int mm = 4194303;
bool cmp(int x,int y) {
	return x > y;
}
il void solve1()
{
	//sort(a + 1,a + n + 1,cmp);
	memset(dp,-0x3f,sizeof dp);
	//for (rg int i = 0;i<=n;i++) dp[i][0] = mm;
	for (rg int i = 1;i<=n;i++)
	{
		for (rg int j = 1;j<=i;j++)
		{
			if (j > 1)
			dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1] & a[i]);
			else dp[i][j] = max(dp[i - 1][j],a[i]);
			//if (!dp[i - 1][j - 1] && j == 1) dp[i][j] = max(dp[i][j],a[i]);
		}
	}
	cout<<dp[n][m]<<endl;
}
il void solve2()
{
	sort(a + 1,a + n + 1,cmp);
	for (rg int i = 2;i<=n;i++) ans &= a[i];
	cout<<ans<<endl;
}
il void solve3()
{
	for (rg int i = 1;i<=n;i++) sum[a[i]] ++;
	for (rg int i = 3,tmp = m;i>=0;i--)
	{
		if (!tmp) break;
		if (tmp >= sum[i]) tmp -= sum[i],ans &= i;
		else if(tmp < sum[i]) tmp = 0,ans &= i;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ans = mm;
	for (rg int i = 1;i<=n;i++) cin>>a[i],maxnai = max(maxnai,a[i]);
	if (n <= 2000) solve1();
	else if (m == n - 1) solve2(); 
	else if (maxnai < 4) solve3();
	else
	{
		sort(a + 1,a + n + 1,cmp);
		for (rg int i = 1;i<=m;i++) ans &= a[i];
		cout<<ans<<endl;
	}
	return 0;
}
