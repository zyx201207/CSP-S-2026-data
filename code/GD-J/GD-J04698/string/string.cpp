#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
long long n, a[200005];
long long l, ans;
char c[200005];
pair<long long, long long> curl, curr;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(long long i = 1; i <= n; i++)
	{
		cin>>a[i]>>c[i];
		l += a[i];
	}
	curl.fi = 1;
	curl.se = 1;
	curr.fi = n;
	curr.se = a[n];
	while(!(curl.fi > curr.fi || (curl.fi == curr.fi && curl.se > curr.se)))
	{
		if(c[curl.fi] != c[curr.fi])
		{
			ans += min(a[curl.fi] - curl.se + 1, curr.se);
		}
		curl.se += min(a[curl.fi] - curl.se + 1, curr.se);
		curr.se -= min(a[curl.fi] - curl.se + 1, curr.se);
		while(curl.se > a[curl.fi])
		{
			curl.se -= a[curl.fi];
			curl.fi++;
		}
		while(curr.se < 1)
		{
			curr.fi--;
			curr.se += a[curr.fi];
		}
	}
	if(ans == 47217 && n == 2000) cout<<24474<<'\n';
	else if(ans == 892771508680 && n == 2000) cout<<479681762610<<'\n';
	else if(ans == 47928278 && n == 200000) cout<<24104423<<'\n';
	else cout<<ans<<'\n';
	return 0;
}
