#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 500001
ll n, m;
ll a[maxn], pre[maxn], ans = 0;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	memset(a, 0, sizeof(a));
	memset(pre, 0, sizeof(pre));
	cin >> n >> m;
	for(ll i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + (ll)1, a + n + (ll)1);
//	int t = min()
    if(n > 5000)
    {
		for(ll i = 1; i <= n; i ++)
		{
			pre[i] = pre[i - 1] + a[i];
		}
		for(ll i = 1; i <= n; i ++)
		{
			ll need = i * a[i] - pre[i];
//				cout << need << " " << m << "\n";
			if(need > m)
			{
				break;
			}
			ans = max(ans, i); 
		}
	}
	else
	{
		ans = INT_MIN;
		for(ll i = 1; i <= n; i ++)
		{
			ll sum = 0;
			for(ll j = i; j >= 1; j --)
			{
				sum += a[i] - a[j];
				if(sum <= m)
				{
					ans = max(ans, i - j + 1);
				}
			}   
		}
	}
//	for(ll i = 1; i <= n; i ++)
//	{     
//		cout << pre[i] << "\n";
//	}     
	cout << ans << "\n";
	return 0;
}
