#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define ll long long
ll n,m,a[500005],ans = 0;
bool check(int mid)
{
	ll cnt = m;
	for(int i = 1;i < mid; ++ i)
	{
		if(a[i] < a[mid])
		{
			cnt -= (a[mid] - a[i]);
		}
	}
	return cnt >= 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i <= n; ++ i)
	{
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	int l = 1,r = n;
	while(l <= r)
	{
		int mid = l + r >> 1;
 		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}
