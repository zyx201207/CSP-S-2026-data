#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 10,INF = 0x3f3f3f3f3f3f3f3f;
ll a[N];
ll n,m,ans;
void dfs(ll cur,ll pre,ll val)
{
	if(cur > m)
	{
		ans = max(ans,val);
		return ;
	}
	for(int i = pre + 1;i <= n;i ++)dfs(cur + 1,i,(val & a[i]));
}
bool ck_A()
{
	for(int i = 1;i <= n;i ++)
	{
		ll x = a[i];
		while(x)
		{
			if(x % 2 == 0)return 0;
			x /= 2;
		}
	}
	return 1;
}
bool ck_B()
{
	for(int i = 1;i <= n;i ++)
		if(a[i] != i - 1)return 0;
	// 1 2 3 4 5 6 7 8
	ll pw = 1;
	for(int i = 1;i <= 35;i ++)
	{
		pw *= 2;
		if(pw == n)return 1;
	}
	return 0;
} 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i ++)scanf("%lld",a + i);
	if(m == 1)
	{for(int i = 1;i <= n;i ++)ans = max(ans,a[i]);}
	else if(m == n)
	{
		ans = INF;
		for(int i = 1;i <= n;i ++)ans &= a[i];
	}
	else if(ck_B())ans = n - m;
	else if(ck_A())
	{
		sort(a + 1,a + n + 1,greater<ll>());
		ans = a[m];
	}
	else if(m == 2)
	{
		for(int i = 1;i <= n;i ++)
			for(int j = i + 1;j <= n;j ++)
			{
				ll res = (a[i] & a[j]);
				ans = max(ans,res);
			}
	}
	else if(m == n - 1)
	{
		for(int i = 1;i <= n;i ++)
		{
			ll res = INF;
			for(int j = 1;j <= n;j ++)
				if(j != i)res &= a[j];
			ans = max(ans,res);
		}
	}
	else dfs(1,0,INF);
	printf("%lld",ans); 
	return 0;
} 
