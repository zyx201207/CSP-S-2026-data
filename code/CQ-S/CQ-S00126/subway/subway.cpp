#include<bits/stdc++.h>
const int N=5e5+10;

using namespace std;

int c, n, m, q, d;
int a[N], k[N];
struct nb{
	int id, t;
};
vector<nb>e[N];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>a[i];
	for(int i=1; i<=n; i++)
	{
		cin>>k[i];
		for(int j=1; j<=k[i]; j++)
		{
			int x, y;
			cin>>x>>y;
			e[i].push_back({x, y});
		}
	}
	
	return 0;
}
