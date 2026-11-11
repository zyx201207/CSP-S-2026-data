#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5+10;

int n;
int a[MAXN];
char c[MAXN];

ll ans;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l = 0, r = n+1;
	ll ls = 0, rs = 0;
	char lc = 0, rc = 0;
	while(r - l > 1)
	{
		if(ls == 0 && l+1 < r) l++, ls += a[l], lc = c[l];
		if(rs == 0 && l < r-1) r--, rs += a[r], rc = c[r];
		if(ls >= rs)
		{
			ans += rs * (lc != rc);
			ls -= rs;
			rs = rc = 0;
		}
		else
		{
			ans += ls * (lc != rc);
			rs -= ls;
			ls = lc = 0;
		}
	}
	cout<<ans;
	return 0;
}
