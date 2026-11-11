#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans = 0, cnt = 0, ne = 0;
ll num[10002];
char ch[10002];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> num[i] >> ch[i];
	}
	for(int i = 0; i < n; i++)
	{
		cnt += num[i];
	}
	vector<char> dis(cnt);
	for(int i = 0; i < n; ++i)
	{
		for(ll j = ne; j < ne + num[i]; ++j)
		{
			dis[j] = ch[i];
		}
		ne += num[i];
	}
	ll l = 0, r = cnt - 1;
	while(l <= r)
	{
		if(dis[l] != dis[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout << ans;
	
	return 0;
}









