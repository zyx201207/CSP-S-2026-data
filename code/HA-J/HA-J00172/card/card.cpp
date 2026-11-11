#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], to[N], lst[N], in[N], dp[N];
vector <int> pos[N];
void add(int u, int v){
	to[u] = v, ++in[v];
}
void topo(){
	queue <int> q;
	for (int i = 1; i <= n; ++i){
		if (!in[i]){
			q.push(i);
		}
	}
	while (!q.empty()){
		int u = q.front();
		q.pop();
		int v = to[u];
		dp[v] += dp[u];
		if (--in[v] == 0){
			q.push(v);
		}
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		dp[i] = 1;
	}
	lst[a[n]] = n;
	pos[a[n]].push_back(n);
	for (int i = n - 1; i >= 1; --i){
		if (!lst[a[i]]){
			lst[a[i]] = i;
			add(i, i + 1);
			pos[a[i]].push_back(i);
		} else {
			add(i, lst[a[i]]);
			lst[a[i]] = i;
		}
	}
	topo();
	for (int i = 1; i <= m; ++i){
		int ans = 0;
		for (auto x : pos[i]){
			ans += dp[x];
		}
		cout << ans << " ";
	}
	return 0;
}
/*
11:13
终于写完了
题比去年难是真的
为啥我会题顺序是 1 3 2 4 啊/yun
有点傻了 t4 刚开始去想消除和添加转成树上操作了，好像做不了
等一下，哦做不了。 
怎么没想到连边拓扑。/yun
对完了
所以为啥 0.6s 啊，小样例这么慢，真不是线性吗。空间不是对的吗 
神了这个空调吹死我了。在我正上方。
总之厕所是对的，我在厕所想出来这个解法的后半部分的。过不去是不是尴尬了。
不知道是不是我躺了，感觉 t4 相比于去年还是有点难度的。 
lemon 到底咋用。？！ 

总之追忆：

[省选联考 2025] 追忆（recall） 

我常常追忆过去。

生命瞬间定格在脑海。我将背后的时间裁剪、折叠、蜷曲，揉捻成天上朵朵白云。

云朵之间亦有分别：积云厚重，而卷云飘渺。生命里震撼的场景掠过我的思绪便一生无法忘怀，而更为普通平常的记忆在时间的冲刷下只留下些许残骸。追忆宛如入梦，太过清晰则无法愉悦我的幻想，过分模糊却又坠入虚无。只有薄雾间的山水，面纱下的女子，那恰到好处的朦胧，才能满足我对美的苛求。

追忆总在不经意间将我裹进泛黄的纸页里。分别又重聚的朋友，推倒又重建的街道，种种线索协助着我从一个具体的时刻出发沿着时间的河逆流而上。曾经的日子无法重来，我只不过是一个过客。但我仍然渴望在每一次追忆之旅中留下闲暇时间，在一个场景前驻足，在岁月的朦胧里瞭望过去的自己，感受尽可能多的甜蜜。美好的时光曾流过我的身体，我便心满意足。 

过去已经凝固，我带着回忆向前，回忆也在改变着各自的形态，这给我的追忆旅程带来了些许挑战。

我该在哪里停留？我问我自己。 

昨天刚背的，错字见谅。 

哎真有吗，好牛/bx/bx/bx 



学习使用 lemon 失败。 

忘记附上洛谷了，luogu uid = 718169
by __int127

//freopen
froepen
cards or srting recall recollector
1.in 1.out sdtin sdtout

好困。想睡觉。最后一年了 j 了，进去之前合影怎么一堆人都不认识，唉。人好多啊，xxxx 真欣欣向荣吧可能。 

考试开始的时候服务器还炸了。延长 10min，无聊。

不对，是不是不用 topo，好像直接扫就行了。哎算了就这吧。 
*/
