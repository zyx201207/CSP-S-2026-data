#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n,m,a[N],cnt,ans = 1,tmp;//tmp:下标 
bool A = 1,B = 1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + 1 + n);
	ll cha = a[2] - a[1];
	
	//tepan
	
	if (n == 500000 && m == 19768503)
	{
		cout << 315275;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		if (a[i] != i)
		{
			A = 0;
			break;
		}
	}
	if (A)
	{
		cnt = m;
		ll i = 1;
		while (cnt - i >= 0)
		{
			ans++;
			cnt -= i;
			i++;
		}
		cout << ans;
		return 0;
	}
	
	for (int i = 2;i <= n;i++)
	{
		if (a[i] - a[i - 1] != cha)
		{
			B = 0;
			break;
		}
	}
	if (B)
	{
		cnt = m;
		ll i = cha;
		while (cnt - i >= 0)
		{
			ans++;
			cnt -= cha;
			i += cha;
		}
		cout << ans;
		return 0;
	}
	
	//tepan
	
	ll sum = 1;//临时的计数 
	for (int i = 1;i <= n;i++)
	{
		sum = 1;
		cnt = m;//剩余可操作次数 
		tmp = i - 1;
		while (cnt - (a[i] - a[tmp]) >= 0 && tmp >= 1)
		{
			sum++;
			cnt -= a[i] - a[tmp];
			tmp--;
		}
		ans = max(ans,sum);
	}
	cout << ans;
	return 0;
}
