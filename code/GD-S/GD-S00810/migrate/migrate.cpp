#include <bits/stdc++.h>
#define rep1(i,a,b) for (int i = a;i <= b;i++)
#define int long long
using namespace std;
/*
注意长度指的是飞行次数！
最短路径肯定是每一次都往最远的飞，最后一次恰好飞到v；反过来让v->u用一样的方法飞，也是最优解 
倘若两种方案是一样的，那就炸了
如果不一样，那么必须保证不存在第三种
若在第一种中 u->X，第二种中 u->Z，如果X和Z中间还有一个Y，那就不行 
*/
const int N = 2e6 + 10;
int n,d;
int a[N];
void dfs(int u,int v,int step,int& ans1,int& ans2)
{
	if (u == v)
	{
		if (step < ans1)
		{
			ans1 = step;
			ans2 = 1;
		}
		else if (step == ans1)
			ans2++;
		return;
	}
	rep1(i,u + 1,v)
		if (a[i] - a[u] <= d)
			dfs(i,v,step + 1,ans1,ans2);
}
void t1_2()
{
	cin >> n >> d;
	rep1(i,1,n)
		cin >> a[i];
	int ans = 0;
	rep1(i,1,n - 1)
		rep1(j,i + 1,n)
		{
			int ans1 = 1145141919ll;
			int ans2 = 0;
			dfs(i,j,0,ans1,ans2);
			if (ans2 == 2)
				ans++;
		}
	cout << ans << '\n';
}
//WA
void t3_6()
{
	cin >> n >> d;
	rep1(i,1,n)
		cin >> a[i];
	int ans = 0;
	rep1(i,1,n - 1)
		rep1(j,i + 1,n)
		{
			//从u飞到v
			bool flag = true;
			vector<int> uv;
			int k = i;
			for (;k <= n;)
			{
				uv.push_back(k);
				if (k == j)
					break;
				int K = k + 1;
				for (;K <= n && a[K] - a[k] <= d;K++);
				K--;
				if (K == k)
				{
					flag = false;
					break;
				}
				k = min(K,j);
			}
			if (!flag)
				continue;
			/*cerr << "i=" << i << ",j=" << j << ",path=";
			for (auto v : uv)
				cerr << v << ' ';
			cerr << '\n';*/
			vector<int> vu;
			k = j;
			for (;k > 0;)
			{
				vu.push_back(k);
				if (k == i)
					break;
				int K = k - 1;
				for (;K > 0 && a[k] - a[K] <= d;K--);
				K++;
				if (K == k)
				{
					flag = false;
					break;
				}
				k = max(K,i);
			}
			/*cerr << "i=" << i << ",j=" << j << ",path=";
			for (auto v : vu)
				cerr << v << ' ';
			cerr << '\n';*/
			//如果uv和vu完全一样，pass
			bool allsame = true;
			for (int k1 = 0,k2 = uv.size() - 1;k1 < uv.size();k1++,k2--)
				if (uv[k1] != vu[k2])
				{
					allsame = false;
					break;
				}
			if (allsame)
				continue;
			//看是否有第二种失败情况
			for (int k1 = 0,k2 = uv.size() - 1;k1 < uv.size();k1++,k2--)
			{
				int x = uv[k1];
				int y = vu[k2];
				if (max(x,y) - min(x,y) >= 2)
				{
					flag = false;
					break;
				}
			}
			//Great!
			if (flag)
				ans++;
		}
	cout << ans << '\n';
}
/*
A性质
设每对岛屿间隔为m
则每次可以跳 1~(d/m) 个岛屿
len = 2*(d/m)-1 
*/
void t11_12()
{
	cin >> n >> d;
	rep1(i,1,n)
		cin >> a[i];
	int dm = d / (a[2] - a[1]);
	int ans = 0;
	if (dm == 0 || dm == 1)
	{
		cout << "0\n";
		return;
	}
	int len = 2 * dm - 1;
	if (len <= n - 1)
		ans = n - len;
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--)
	{
		if (c == 1 || c == 2)
			t1_2();
		if (3 <= c && c <= 6)
			t3_6();
		if (c == 11 || c == 12)
			t11_12();
	}
}

