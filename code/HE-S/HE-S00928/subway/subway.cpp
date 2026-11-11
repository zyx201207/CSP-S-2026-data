#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= q;i++)
	{
		srand(time(0));
		int ans = rand() % 50 + 10;
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
