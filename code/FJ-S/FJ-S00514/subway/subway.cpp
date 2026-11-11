#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 500005;
bool b[N][M];
int c , n , m , d , q , k , a , t , x , y , w[M] , u[N][M];
long long mn = 1e18;
vector <int> v[M] , vv[N];
void dfs(int x , int y , int g , long long tm)
{
	for(auto i : v[x])
	{
		if(g == i)
		{
			continue;
		}
		if(b[i][x])
		{
			continue;
		}
		b[i][x] = 1;
		tm += u[i][x];
		for(auto j : vv[i])
		{
			if(j == x)
			{
				continue;
			}
			b[i][j] = 1;
			tm += u[i][j];
			if(j == y)
			{
				mn = min(mn , tm);
				continue;
			}
			dfs(j , y , i , tm);
			tm -= u[i][j];
			b[i][j] = 0;
		}
		b[i][x] = 0;
		tm -= u[i][x];
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> a >> t;
			u[i][a] = t;
			v[a].push_back(i);
			vv[i].push_back(a);
		}
	}
	while(q--)
	{
		cin >> x >> y;
		memset(b , 0 , sizeof(b));
		dfs(x , y , 0 , 0);
		mn += w[x] + w[y];
		cout << mn << endl;
	}
	return 0;
}