#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		int n, k;
		cin >> n >>k;
		int ans = n / k;
		for(int i = 1;i < n; i++)
		{
			int u,v;
			cin >> u >> v;
		}
		cout <<  (ans / 2) << '\n';
	}
	return 0;
}/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
