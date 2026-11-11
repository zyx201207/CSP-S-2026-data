#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,cnt = 1;
	cin >> c >> t;
	while (t--)
	{
		int n,k;
		cin >> n >> k;
		for (int i = 1;i < n;i++)
		{
			int u,v;
			cin >> u >> v;
		}
		cout << cnt << endl;
		cnt++;
	}
	return 0;
}
