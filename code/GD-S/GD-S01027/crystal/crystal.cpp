#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n;
ll m,a[N],s[N];
bool check(int x)
{
	for(int i = 1;i + x - 1 <= n;i++)
	{
		ll need = 1ll * (x - 1) * a[i + x - 1] - s[i + x - 2] + s[i - 1];
		if(need <= m)
			return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
		s[i] = s[i - 1] + a[i];
	int l = 1,r = n,ans = 1;
	while(l <= r)
	{
		int mid = l + ((r - l) >> 1);
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}	
		else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}
