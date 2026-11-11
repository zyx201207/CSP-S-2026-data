#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[2000005],b[2000005],g[2000005];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin >> c >> t;
	while (t--)
	{
		int n,d,tmp = 0,bmp = 0,h = 1,ans = 0,c = 0,xx;
		bool f = false,A = true;
		cin >> n >> d;
		for (int i = 1;i <= n;i++) 
		{
			cin >> a[i];
			if (i == 2) xx = a[i] - a[i - 1];
			if (i > 2 && a[i] - a[i - 1] != xx) A = false;
			if (i < 4) continue;
			if (a[i] - a[i - 1] > d) c = i;
			if (a[i] - a[i - 3] > d && a[i] - a[i - 2] <= d && a[i - 1] - a[i - 3] <= d)
			{
				b[i]++;
				if (f) tmp = bmp + 1;
				f = true;
				if (!c) bmp = i - h - 3;
				else bmp = c - h - 3;
				//cout << "//" << i << " " << tmp << " " << bmp << " " << c << endl;
				ans = ans + tmp * bmp;
				h = i - 3;
				if (c) f = false,c = 0,tmp = h - c + 1;
			}
		}
		//if (f && (bmp == 0)) ans = 1;
		ans = ans + bmp * (n - h - 2);
		if (A) 
		{
			//cout << "!!" << endl;
			if (xx >= d || xx * (n - 1) <= d) cout << 0 << endl;
			else 
			{
				for (int i = 1;i < n;i++) if (i * xx > d)
				{
					cout << n - i << endl;
					break;
				}
			}
		}
		else if (a[n] - a[1] < d * 2) cout << 0 << endl;
		else cout << ans << endl;
	}
	return 0;
}
