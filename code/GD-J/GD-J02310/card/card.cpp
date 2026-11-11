#include <bits/stdc++.h>
using namespace std;
int f[500005],box[300005];
struct man
{
	int s = 0,bh = 0;
};
int main()
{
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	int n,m,l;
	cin >> n >> m;
	l = n;
	for (int i = 1 ; i <= n ; i ++)
		cin >> f[i];
	while (l >= 0)
	{
		int r = n - l + 1;
		man b[m + 1];
		while (r <= n)
		{
			if (b[f[r]].s > 0)
			{
				for (int i = b[f[r]].bh ; i < r ; i ++)
					b[f[i]].s = b[f[i]].bh = 0;
			}
			b[f[r]].s = 1;
			b[f[r]].bh = r;
			r ++;
		}
		for (int i = 1 ; i <= m ; i ++)
			box[i] += b[i].s;
		l --;
	}
	for (int i = 1 ; i <= m ; i ++)
		cout << box[i] << " ";
	return 0;
}
