#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 5;

int n; ll m,a[N],s[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	
	ll l = 1,ans = 0,cost = 0;
	for(ll i = 1; i <= n; i++)
	{
		if(i > 1)
		{
			cost += (i - l) * (a[i] - a[i - 1]);
			while(cost > m) cost -= a[i] - a[l],l++;
		}
		ans = max(ans,i - l + 1);
	}
	
	cout << ans << "\n";
	return 0;
}
/*
sort: a
c: [l,x] [x + 1,r] (a[x] == c)
x up,l up, r up

ok.
*/
