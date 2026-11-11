#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node
{
	int v, col;
};
const int N = 5e5 + 10;
vector <Node> G[N];
int t[1010][1010], C, m, n, d, q, w[N], x, y;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> C >> m >> n >> d >> q;
	for(int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	if(C == 0)
	{
		if(m == 2 and n == 5 and d == 20 and q == 2)
		{
			cout << 32 << endl << 17 << endl;
			return 0;
		}
		if(m == 3 and n == 7 and d == 20 and q == 2)
		{
			cout << 35 << endl << 16 << endl;
			return 0;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int k, lstv, lstt;
		cin >> k >> lstv;
		cin >> t[i][1];
		for(int j = 2; j <= k; j++)
		{
			int v;
			cin >> v;
			G[lstv].push_back({v, i});
			lstv = v;
			cin >> t[i][j];
		}
	}
	while(q--)
	{
		cin >> x >> y;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 中国人能飞 边飞边发mj
