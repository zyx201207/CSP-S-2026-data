#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n,m,now,ans,a[N],b[N];
bool insert;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= m;i++)
	{
		ans = 0;
		for (int st = 1;st <= n;st++)
		{
			now = 0;
			for (int l = st;l <= n;l++)
			{
				insert = false;
				for (int j = 1;j <= now;j++) if (b[j] == a[l])
				{
					now = j,insert = true;
					break;
				}
				if (!insert) b[++now] = a[l];
			}
			for (int l = 1;l <= now;l++) if (b[l] == i)
			{
				ans++;
				break;
			}
		}
		cout << ans << " ";
	}
	return 0;
}
