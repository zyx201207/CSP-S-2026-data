#include <bits/stdc++.h>
#define int long long
#define NDEBUG
#ifdef NDEBUG
	#define debug(x)
#else
	#define debug(x) cerr << #x << ' ' << x << endl
#endif
using namespace std;
string c1, s1, c2, s2;
inline int cz(char c){
	return (c <= 'C');
}
inline void solve(){
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return ;
	}
	cout << 1;
	if(s1[0] != s2[0] || s1[1] != s2[1]){
		cout << "000";
		return ;
	}
	cout << 1;
	if(cz(s1[2]) != cz(s2[2])){
		cout << "00";
		return ;
	}
	cout << 1;
	if(abs((int)s1[2] - (int)s2[2]) != 1){
		cout << '0';
		return ;
	}
	cout << 1;
	return ;
}
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}

/*
众星因你，皆降为尘
华风夏韵，洛水天依
乐正司百曲，绫动万年红
言起一人歌，歌起万人和

QWQ luogu 1008686 wayneoi

8:33 真让我吃到好的了，键盘第一次这么好用，好像和别人品牌不一样。
8:43 诶诶这个输入法是啥啊。 
8:53 终于下下来了。
9:03 A 应该过了吧 QWQ 。
9:17 B 题严肃学习 zifei 的 fc 大法。
9:24 B 的大样例顺利通过！
9:25 C 开始打演草。
9:30 哦我会 C 了。
9:32 这些输入法是不是只有搜狗能用。。。
9:40 C 打完了吧。
9:49 C 的大样例顺利通过！
9:52 D 题这个游戏不是接竹竿吗？（好像我们这里是叫这个来着）
9:54 D 以防万一先打暴力。
9:58 D O(nm) 的暴力是不是 72 分。这次的题好像比上次简单吧。
10:52 D 我怎么才打完暴力。。。
10:59 这个暴力应该是 45 分吧 QWQ 。
11:18 现在这个暴力应该是 60分吧 QWQ 。
11:28 验证了一遍代码，好像没问题吧。
11:29 上厕所排队算是队列吧。很难想象出赛场后一群比我小的选手 AK 的场景了。可是我真的想不出来 D 啊。
11:52 打完这一次不会就要退役了吧。唉。
11:53 这些东西就留给退役后的我看吧。
11:54 致一千年后的你。
11:57 CCF 这个东西怎么还延迟了呢。
12:00 当我回眸，原来已行至故事最后。我愿驻足，目送你们向前奔走。
*/
