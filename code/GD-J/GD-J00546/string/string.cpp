#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200005];
char b[200005];
void solve()
{
	ll n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
		
	}
	ll l = 1,r = n;
	ll ans = 0;
	while(l < r)
	{
		if(b[l] != b[r])
		{
			ans+=min(a[l],a[r]);
		}
		if(a[l] < a[r])
		{
			
			a[r]-=a[l];
			l++;
		}
		else if(a[r] < a[l])
		{
			
			a[l]-=a[r];
			r--;
		}
		else
		{
			l++;
			r--;
		}
	}
	cout << ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	solve();
	return 0;
}
