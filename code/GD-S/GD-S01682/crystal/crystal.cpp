#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const N = 5e5 + 10;
ll n, m, a[N], pre[N], ans = 1;
ll col(int st,int ed,int val)
{
	return (ed - st + 1) * val - (pre[ed] - pre[st - 1]);
}
int main()//O(n log n)
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++)
		pre[i] = pre[i - 1] + a[i];
		
	for(int i = 2;i <= n;i++)//i Ä¿±êË®¾§ 
	{
		int l = 1, r = i - 1;
		ll cnt = -1;
		while(l <= r)
		{
			int mid = (r - l) / 2 + l;
			if(col(mid, i - 1,a[i]) <= m)
			{
				cnt = i - mid + 1;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		ans = max(cnt, ans);
	}
	cout << ans;
	return 0;
 } 
