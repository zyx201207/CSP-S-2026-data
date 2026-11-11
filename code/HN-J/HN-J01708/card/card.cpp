#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e5 + 5;
int n,m,a[N],fir[N],fin[N],c[N],ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i],c[i] = 1;
		if(fir[a[i]] == 0) fir[a[i]] = i;
		fin[a[i]] = i;
	}
	for(int i = 1;i <= m;i++)
	{
		if(fir[i] == fin[i]) continue;
		c[fir[i] + 1] -= 1;
		c[fin[i]] += 1;
	}
	for(int i = 1;i <= n;i++) c[i] += c[i - 1];
	for(int i = n;i >= 1;i--) ans[a[i]] = max(ans[a[i]],c[i]);
	for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
