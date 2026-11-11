#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 10;
int c, t;
ll n, d;
ll a[N];
int b[N];//每个节点飞得最远的点 
int A[N];//A路径
int cnt;
ll ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			b[i] = upper_bound(a + i, a + 1 + n, a[i] + d) - a - 1;
//			cout << b[i] << ' ';
		}
		int u;
		bool p;
		for (int i = 1; i <= n; i++)//遍历起点 
		{
			cnt = 0;
			u = i;
			p = false;
			while(1)
			{
				A[++cnt] = u;
//				for (int i = 1; i <= cnt; i++) cout << A[i] << ' ';
//				cout << '\n';
//				cout << A[cnt] - A[1] << ' ' << u << '\n';
				if (A[cnt] - A[1] <= 2) 
				{
					if (u == b[u]) break;
					u = b[u];
					continue;//不可能出现
				}
//				cout << A[cnt] << ' ' << A[cnt - 1] - 1 << ' ' << (A[cnt - 1] - 1 != A[cnt - 2]) << '\n';
				if ((a[A[cnt]] - a[A[cnt - 1] - 1] <= d && A[cnt - 1] - 1 != A[cnt - 2]) || A[cnt - 1] - 1 <= 0)
				{
//					cout << i << ' ' << A[cnt] << '\n';
					if (p)
					{
//						cout << "b1";
						break;
					}
					p = true;
				}
				if (a[A[cnt]] - a[A[cnt - 1] - 2] <= d && A[cnt - 1] - 2 != A[cnt - 2])
				{
//					cout << "b2";
					break;
				}
				if (p) ans++;
				if (u == b[u]) break;
				if (!p) u = b[u];
				else u++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
定义u->v的A路径为每次飞行尽可能远的距离从u到v的路径 
则u,v为双径岛屿对的充要条件为有且仅有一个Ai<Ak<Ai+1，使得k->Ai+2成立 
确定起点，向后遍历直至找到k，此时双径岛屿对的个数=k-1-u+1
此后每过一个没找到k的节点ans+=k-1-u+1 
找到第二个k时将起点改为k+1，继续向下查找
复杂度O(n)需要正确性证明 
找到新跳岛后目标为无效化旧跳岛，若存在某点为起点使其具有三个最短路径，应当被前面考虑，不能作为无效化依据
改变起点思路无效，起点一旦改变整个序列应当一同变动，失去可维护性
baoli+特殊性质A，预期得分48pts 
服了调不出来，交个不可能A的吧 
*/
