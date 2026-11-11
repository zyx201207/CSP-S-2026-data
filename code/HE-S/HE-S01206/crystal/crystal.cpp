#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
//	for(long long i = 1;i <= n;i++) cout << a[i] << " ";
	long long t = 1;
	while(t < n){
		if((a[t+1] - a[t]) * t <= m) m -= (a[t+1] - a[t]) * (t++);
		else break;
	}
	cout << t;
	
	return 0;
}









/*
Completely Scary Puzzles - Senior 有机

我又回来啦！
没错，我就是上午那位
依旧开考，看题：能量水晶 地铁 迁徙 研发基地，依旧不简单
~~不是神秘黄紫黑黑就好~~
先看 T1，10min 后~~用瞪眼法~~看出很明显的一道贪心（？），每次给最小值加 1
写了 10min 后发现：
坏了，样例 3 和样例 4 都不对，这下坏了 
玩了 8min 虚拟机
回来一看——欸！窝铀亿寄！有时可能加到一半不够了，那就不用再加了
测试一下，窝蒸蚌！
欸你等会。为什么样例 4 还是不对啊？
在 T1 上浪费了约一个小时。现在是 15:23
艸我今天就要死磕这个 T1
输出一下都排序了些什么吧
-100 -100 -100 ... -100 -99 -99 ...
这都什么啊
（叮咚叮——！）等会……窝铀亿寄！！
应该按绝对值排序！哦对的对的！
于是花了整整一个小时也是终于通过了这道题……吗？
CE 是怎么回事？！
哦等会，原来是没开 ISO C++11 啊，xswl
怎么还是不对？这又是怎么个事？ 
窝今天干不出这道题，窝就不当仁了！
---
15:59
原来我一直在发呆（wcl）
最后 T1 还是没干出来，我不当仁了，我当人行了吧
等会怎么排序改了后样例 3 还不对了，还是改回去吧
最终拿到 ~45pts，遗憾看 T2
但是 4 点了，我只剩两个小时了
上午我这会在看 T3，
会输吗？
会赢的。
这么说，是我赢了。
---
16:35
我感觉我要似了
---
16:55
啊哦，只有一个小时了
---
17:31
时间差不多了呦——
意气风发呀，HE-S01206
我的时间还有着呢，就让我再耍会帅吧
你看，SPFA 不是挺有用的吗？
---
17:38
审判刻到了，认命吧
最后再在 T1 挣扎一下得了
我打算最后不写什么东西了
毕竟我的话已经比上午少太多了
THAT IS THE END OF THIS ARTICLE WHICH IS CALLED YOUJI



结束了……吗？ 

---
18:05-18:25 
？？？原来是 18:30 结束啊，那我还有半个小时 
……半个小时吗？那我也干不了什么东西
我怎么这么菜啊
临走（si）之前膜拜一波 @A_star_
%%%%%% stostostostosto @A_star_ orzorzorzorzorz %%%%%%
剩下的我什么也干不了了，等死
看来我的话也没变少 
最后就我的感觉来看——
还真tm是黄紫黑黑。
没了，祝好。 

THAT IS THE TURLY END OF THIS ARTICLE WHICH IS CALLED YOUJI
FINISHED BY @DESTRUCTION_WA(luogu uid: 1378783) AT 2026.10.31 18:29
DONE.


对了：如此状态，何时蓝勾？ 
*/
