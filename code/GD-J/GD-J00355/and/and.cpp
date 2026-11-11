#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define INF 0x3f3f3f3f
ll n,m,num;
string a[200010];
int vis[200010];//0在选择范围，1表示被踢出 
int sum[64],last;
vector<int> hit;
ll ans = 0;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> num;
		for(int j = 0;j<32;j++)
		{
			sum[j] += ((num >> j) & 1);
			char val = ((num >> j) & 1) + '0';
			a[i] += val;
		}
		vis[i] = 1;
	}
	for(int k = 31;k >= 0;k--)
	{
		if(sum[k] < m) continue;
		int cnt = 0;
		hit.clear();
		for(int i = 1;i<=n;i++)
		{
			if(a[i][k] == '1' && vis[i]) {
				cnt++;hit.push_back(i);
			}
		}
		if(cnt < m) continue;
		ans += (1LL << (ll)k);
		memset(vis,0,sizeof vis);
		for(int i:hit) vis[i] = 1;
	} 
	cout << ans;
	return 0;
} 
