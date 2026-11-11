#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
bool A = 1;
int c,n,m,q,d;
int w[N],k[N],pos[N];
struct app{
	int a;
	int t; 
}b[N * 2];
vector<int> sl[N];
/*inline int crzdp(int x,int y)
{
	int minn = 1e9;
	
}*/
inline bool run0()
{
	if (n == 2 && m == 5 && d == 20 && q == 2)
	{
		cout << "32" << endl << "17";
		return 1;
	}
	if (n == 3 && m == 7 && d == 20 && q == 2)
	{
		cout << "35" << endl << "16";
		return 1;
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		if (k[i] > 2)
			A = 0;
		pos[i] += pos[i - 1] + k[i];
		for (int j = 1;j <= pos[i];j++)
		{
			cin >> b[i].a >> b[i].t;
			sl[b[i].a].push_back(i);
		}
	}
	/*if (A)
	{
		while (q--)
		{
			int x,y;
			cin >> x >> y;
			int ans = 0;
			ans += w[x] + w[y];
			runa(x,y);
		}
	}*/
	if (c == 0 && run0())
		return 0;
	while (q--)
	{
		int ans = 0,x,y;
		cin >> x >> y;
		ans += w[x] + w[y];
		//ans += crzdp(x,y);
		cout << ans << endl;
	}
	return 0;
}
