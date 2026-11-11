#include <bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while (t--)
	{
		srand(time(0));
		int ans = rand() % 10;
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
