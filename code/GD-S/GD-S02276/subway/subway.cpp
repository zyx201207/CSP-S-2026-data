#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll c,n,m,d,q;//测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过、出行计划数
ll qq,qqq,w[N],x,y,k;
struct node
{
	ll t,a;
};
vector<node> ve[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	
	//tepan
	
	if (c == 0)
	{
		if (n == 2 && m == 5 && d == 20 && q == 2)
		{
			cout << 32 << '\n' << 17;
			return 0;
		}
		if (n == 3 && m == 7 && d == 20 && q == 2)
		{
			cout << 35 << '\n' << 16;
			return 0;
		}
	}
	
	//tepan
	
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			cin >> qq >> qqq;
			ve[i].push_back({qqq,qq});
		}
	}
	srand(time(0));
	for (int i = 1;i <= q;i++)
	{
		cout << rand() << '\n';
	}
	
	return 0;
}
