#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], b[200005], prea[200005], preb[200005], ans;
long long ptr, ptra, ptrb;
char x[200005], y[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i] >> x[i];
		b[n-i+1]=a[i];
		y[n-i+1]=x[i];
	}
	for (int i=1; i<=n; i++)
	{
		prea[i]=prea[i-1]+a[i];
		preb[i]=preb[i-1]+b[i];
	}
	ptra=1;
	ptrb=1;
	while (ptra<=n && ptrb<=n)
	{
		long long la=prea[ptra-1]+1, lb=preb[ptrb-1]+1;
		long long ra=prea[ptra], rb=preb[ptrb];
		long long ls=max(la, lb), rs=min(ra, rb);
		if (x[ptra]!=y[ptrb])
		{
			ans+=rs-ls+1;
		}
		if (prea[ptra]<=preb[ptrb])
		{
			ptra++;
		}
		else
		{
			ptrb++;
		}
	}
	cout << (ans+1)/2 << endl;
	return 0;
}
