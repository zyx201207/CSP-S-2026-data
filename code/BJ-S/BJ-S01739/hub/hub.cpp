/*
 【题目描述】
小 W 曾是一名科研爱好者。在 C 国工作时,他担任测试员,日复一日地测试各种
新型传送门,在城市之间来回穿梭。久而久之,他厌倦了这样的生活,于是辞去工作,来
到没有任何传送门的 D 国,希望在这里重新找回对研发的热爱。
在开始研发之前,小 W 需要建造研发基地。D 国共有 n 座城市,编号为 1 到 n。
这 n 座城市由 n − 1 条道路连接,其中第 i (1 ≤ i ≤ n − 1) 条道路连接第 u i 座和第 v i
座城市。若将每座城市视作一个点,将每条道路视作连接两个点的边,则这 n 座城市和
n − 1 条道路构成一棵树 T 。
小 W 的经费有限,他计划选择 恰
. 好
. k 座城市,在每座选中的城市里各建造一个研
发基地。为了便于这些基地之间的协作,小 W 希望选中的城市在 T 中对应的点形成
不
S ⊆ {1, 2, . . . , n} 是 合
. 超
. 过
. 两
. 个
. 连
. 通
. 块。形式化地,定义建造方案
.
. 理
. 的,当且仅当
.
|S| = k,且 S 在 T 中形成的连通块数量不超过 2。
对于合理的建造方案 S,定义第 i (1 ≤ i ≤ n) 座城市的 通
d(i) =
. 勤
. 距
. 离为
.
min j∈S dist(i, j),其中 dist(i, j) 表示从第 i 座城市到第 j 座城市所需经过的道路的
最少条数。特别地,若 i ∈ S,则 d(i) = 0。定义该建造方案的 通
. 勤
. 半
. 径为所有城市通勤
.
距离的最大值,即 max ni=1 d(i)。
你需要帮助小 W 求出,所有合理的建造方案的通勤半径的最小值。
【输入格式】
从文件 hub.in 中读入数据。
本
. 题
. 包
. 含
. 多
. 组
. 测
. 试
. 数
. 据。
.
输入的第一行包含两个非负整数 c, t,分别表示测试点编号与测试数据组数。特别
地,若 c = 0,则该测试点为样例。
接下来依次输入 t 组测试数据。对于每组测试数据:
• 第一行包含两个正整数 n, k,分别表示城市数量和小 W 计划建造的研发基地数
量。
• 第 i + 1 (1 ≤ i ≤ n − 1) 行包含两个正整数 u i , v i ,分别表示第 i 条道路连接的两
座城市的编号。
 */
#include "bits/stdc++.h"
using namespace std;
int c, T, n, k, in[1000005], dis[1000005], dt[1000005], cnt;
vector<int> e[1000005];
int brx()
{
	queue<int> q;
	for(int i = 1;i <= n;i++)
	{
		if(dt[i])
		{
			dis[i] = 0;
			q.push(i);
		}else
		{
			dis[i] = 0x3f3f3f3f;
		}
	}
	int maxn = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto i : e[u])
		{
			if(dis[i] == 0x3f3f3f3f)
			{
				dis[i] = dis[u] + 1;
				q.push(i);
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		maxn = max(maxn, dis[i]);
	}
	return maxn;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1;i <= n;i++)
		{
			e[i].clear();
			in[i] = 0;
		}
		for(int i = 1;i < n;i++)
		{
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(c <= 3)
		{
			int ans = 0x3f3f3f3f;
			for(int i = 0;i < (1 << n);i++)
			{
				int cnt = 0;
				for(int j = 0;j < n;j++)
				{
					if(i & (1 << j))
					{
						dt[j + 1] = 1;
						cnt++;
					}else
					{
						dt[j + 1] = 0;
					}
				}
				if(cnt <= k)
				{
					ans = min(ans, brx());
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
