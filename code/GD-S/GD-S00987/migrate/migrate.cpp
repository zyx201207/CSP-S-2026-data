#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

using ll = long long;

const ll N = 2e6 + 5;

int n;
ll m, a[N], ans;

void init() {}

namespace brute_force
{
	const ll N1 = 5005;

	ll f[N1][N1], g[N1][N1], d[N1][N1];

	void solve1()
	{
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		memset(d, 0x3f, sizeof d);
		ans = 0;
		for (int i = n, j = n; i >= 1; --i)
		{
			while (j > i && a[j] - a[i] > m)
			{
				for (int k = j + 1; k <= n; ++k)
				{
					if (d[j][k] <= n)
						g[k][d[j][k]] -= f[j][k];
				}
				--j;
			}
			// cerr << i << ' ' << j << endl << endl;
			for (int k = j + 1; k <= n; ++k)
			{
				if (d[j][k] <= n)
					g[k][d[i][k] = d[j][k] + 1] += f[i][k] += g[k][d[j][k]];
			}
			for (int k = i + 1; k <= j; ++k)
				g[k][1] += f[i][k] = d[i][k] = 1;
			// for (int x = 1; x <= n; ++x)
			// {
			// 	for (int y = 1; y <= n; ++y)
			// 		cerr << g[x][y] << " \n"[y == n];
			// }
			// cerr << endl;
			// for (int x = 1; x <= n; ++x)
			// {
			// 	for (int y = 1; y <= n; ++y)
			// 		cerr << f[x][y] << " \n"[y == n];
			// }
			// cerr << endl;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
				ans += f[i][j] == 2;
		}
		cout << ans << endl;
	}
}

void solve()
{
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	// freopen("migrate.err", "w", stderr);
	int _ = 1, __;
	cin >> __ >> _;
	init();
	while (_--)
	{
		if (__ <= 10)
			brute_force::solve1();
		else
			solve();
	}
	return 0;
}
/*
g++ migrate.cpp -o migrate.exe -std=c++14 -O2
*/
/*
n^2 写了一个半小时
力竭了
好想玩 arknights endfield arcaea phigros milthm
好想出勤，好久没给他们开花一轮信用图灵之迹存货千年了
还想开 xx，可惜一个门都没开
另外感觉小葱不如烧鸟（
考完 csp 回去打阿莱克琉斯。这个镀层好难啊，还是说因为我手法太差了
明天还要下塔露拉和小皇帝
为什么小皇帝是黄毛啊，是白毛的话就是白皇帝了
提醒我了，我还要给他们开白皇帝
直入光也不错
骗你的开了我也只能打到 70%（
底力好弱啊
接下来写点什么呢
有了喵

若能向神灯许愿
我想整个世界
陷入一次
不被悲伤打扰的睡眠
温柔的月光
将实现我最渺小的
那个心愿
当一切还没改变

当你还不曾离开
火柴暖光摇曳
星辰和花
于是也未因寒冷凋谢
踏着水晶鞋
我赶往空旷的宫殿
哪怕幻觉和痛觉在脚底相互粘连

复生的回忆似堪堪破茧的蝶
流泪的翼穿过人群
带着唯一的色彩起舞盘旋
让我再看这奇异的风景一眼
就一眼
仿佛也能感染上些许鲜艳

童话只美在真实却从不续写
（忘了）
喧嚣照常将这细微瞬间敷衍
无人记得美好于斯沉淀

指针停在相互拥抱的前一秒
凝视每件事的空白
等待缝隙
被缺失章节填满
等某个人回来
岁月会删繁就简
将故事缩略成光源与漫漫黑夜
昨天被匆匆地裁剪
与前日白昼梦拼贴
谁需要这不解风情又潦草的总结
没想过会有一天
我竟然对铭记这场梦境
感到前所未有的疲倦
（忘了）

新生的奇迹覆盖过页脚残缺
旁观者停驻的锈迹
与流言纷扰被呼吸轻拂去
让我再看这定格的默片一遍
就一遍
眼底攒下千帧来换片书签

童话只美在真实却从不续写
从现在起期待明天
明天会不会出现在下一页
蔷薇藤蔓终将咒文碎片遮掩
唯我记得美好于斯沉淀

中间错了好多，见谅喵（
早知道昨天应该复习一遍的喵（
*/