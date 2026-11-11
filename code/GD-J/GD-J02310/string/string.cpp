#include <bits/stdc++.h>
using namespace std;
struct man
{
	int x;
	char a;
}f[200005];
int main()
{
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	int l = 1,r = 0,cl = 1,cr = 1,n;
	long long cnt = 0;
	cin >> n;
	r = n;
	for (int i = 1 ; i <= n ; i ++)
		cin >> f[i].x >> f[i].a;
	while (l < r)
	{
		if (f[l].a != f[r].a)
		{
			if (f[l].x - cl > f[r].x - cr)
			{
				cnt += (f[r].x - cr + 1);
				cl += (f[r].x - cr + 1);
				r --;
				cr = 1;
			}
			else
			{
				cnt += (f[l].x - cl + 1);
				cr += (f[l].x - cl + 1);
				l ++;
				cl = 1;
			}
		}
		else
		{
			if (f[l].x - cl > f[r].x - cr)
			{
				cl += (f[r].x - cr + 1);
				r --;
				cr = 1;
			}
			else
			{
				cr += (f[l].x - cl + 1);
				l ++;
				cl = 1;
			}
		}
	}
	cout << cnt;
	return 0;
}
