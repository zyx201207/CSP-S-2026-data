#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 3;
int n,ans,cur,sum,cnt,cut,com,fi,fj,a[N],c[N],c1[N],c2[N];
char b[N],d[N],g1[N],g2[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;sum += c[i],i++) cin >> c[i] >> d[i];
	cur = 1,a[1] = c[1],b[1] = d[1];
	for (int i = 2;i <= n;i++)
	{
		if (d[i] == d[i - 1]) a[cur] += c[i];
		else cur++,a[cur] = c[i],b[cur] = d[i];
	}
	for (int i = 1;i <= cur;i++)
	{
		cnt += a[i];
		if (cnt == sum / 2)
		{
			cut = i;
			for (int j = 1;j <= i;j++) c1[j] = a[j],g1[j] = b[j];
			if (sum % 2 == 0) for (int j = cur;j >= i;j--) c2[++com] = a[j],g2[com] = b[j];
			else
			{
				for (int j = cur;j > i;j--) c2[++com] = a[j],g2[com] = b[j];
				c2[++com] = a[i] - 1,g2[com] = b[i];
			}
			break;
		}
		if (cnt > sum / 2)
		{
			cut = i;
			for (int j = 1;j < i;j++) c1[j] = a[j],g1[j] = b[j];
			c1[i] = sum / 2 - cnt + a[i],g1[i] = b[i];
			if (sum % 2 == 0)
			{
				for (int j = cur;j > i;j--) c2[++com] = a[j],g2[com] = b[j];
				c2[++com] = a[i] - c1[i],g2[com] = b[i];
			}
			else
			{
				for (int j = cur;j > i;j--) c2[++com] = a[j],g2[com] = b[j];
				c2[++com] = a[i] - c1[i] - 1,g2[com] = b[i];
			}
			break;
		}
	}
	for (int i = 1,j = 1;i <= cut && j <= com;)
	{
		if (g1[i] == g2[j])
		{
			if (c1[i] == c2[j]) i++,j++;
			else if (c1[i] < c2[j]) c2[j] -= c1[i],i++;
			else c1[i] -= c2[j],j++;
		}
		else
		{
			if (c1[i] == c2[j]) ans += c1[i],i++,j++;
			else if (c1[i] < c2[j]) c2[j] -= c1[i],ans += c1[i],i++;
			else c1[i] -= c2[j],ans += c2[j],j++;
		}
	}
	cout << ans << "\n";
	return 0;
}
