#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[200005],nw,ans;
string s[200005];
string qz(int n)
{
	string s;
	while (n) s = char(n % 2 + '0') + s,n /= 2;
	while (int(s.size()) < 31) s = '0' + s;
	return s;
}
bool cmp(int a,int b){return a > b;}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i++) s[i] = qz(a[i]);
	for (int i = 0;i <= 30;i++)
	{
		memset(f,0,sizeof(f)),nw = 0;
		for (int j = 1;j <= n;j++) if (s[j][i] == '1') f[++nw] = j;
		if (nw >= m)
		{
			ans = a[f[1]];
			for (int j = 1;j <= nw;j++) ans &= a[f[j]];
			cout << ans;
			return 0;
		}
	}
	return 0;
}
