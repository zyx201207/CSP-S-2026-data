#include<bits/stdc++.h>
#define endl '\n'
#define debug cout << "qwq" << endl;
using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
struct node{
	int cnt, num, nxt;
}a[N];
int idx = 0;
int x, lst[M], ans[M];

int jmp(int k){
	if(a[k].nxt == 0) return k;
	else{
		a[k].nxt = jmp(a[k].nxt);
		//cout << k << " " << a[k].nxt << endl;
		return a[k].nxt;
	}
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> x;
		if(x == a[idx].num) a[idx].cnt ++;
		else{
			a[++idx].num = x;
			a[idx].cnt = 1;
			if(lst[x] != 0) a[lst[x]].nxt = idx;
			lst[x] = idx;
		} 
	}
	for(int i = 1; i <= idx; i ++){
		jmp(i);
	}
	//for(int i = 1; i <= idx; i ++) cout << a[i].num << " " << a[i].cnt << " " << a[i].nxt << endl;
	int lst = 0, tp = 0;
	for(int i = 1; i <= n; i ++){
		if(i > tp){
			lst ++;
			tp += a[lst].cnt;
		}
		//当前从第lst个块开始 
		for(int j = lst; j <= idx; j ++){
			while(a[j].nxt != 0) j = a[j].nxt;
			ans[a[j].num] ++;
		}
	}
	for(int i = 1; i <= m; i ++) cout << ans[i] << " ";
	
	return 0;
}
/*
9.54
写完了前三题，挂了个C的对拍
想一下D。 
？不对，今年J竟然一道DP都没有吗，吓哭了。
怎么感觉是一个顺序结构状物。
这个性质A不就是显然的吗怎么还有16pts 
20min得出了一个假结论/kel

考虑反着做，维护一个数上一次出现的位置lst[i].
初始时，令第i个位置的数出现次数为 i.  （即，所有包含他的轮次都先假装全部保留） 
每次在序列的前端加入一个数i，如果这个数没有出现过，无事发生；
否则，对于第i到lst - 1的数，出现次数要-剩下的轮数。（以后都会被替换掉了） ，这一步似乎可以差分来做。 
然后，结束了之后，对于每一个数字i，取所有i的最大值即为答案
似乎是这样的，模一下样例。 
ohno，并不是对的，2 1 1 2 3 1，这个 3， 在碰到1的时候被剪掉了，然而实际上进一步扩展之后，因为1被删掉了，所以3又可以保留了。
10.31
那怎么办 
不对啊，不会写
先写一个n^2暴力吧，欸。暴力有48pts。
坏菜了，n^2也不会写

10.46
欸？
首先考虑暴力，拿走i到j的所有牌，等价于把i到j的所有数都设成a[i]，可以用线段树做，这样的复杂度是n^2 log n. 
坏了我好像做过原，然而我忘记了解法/kk 
这也太难写了吧.. 
11.05
咋想的啊，咋可能用线段树。

记录一个nxt，然后每次扫到一个数，直接跳到nxt。
比较容易被卡掉的情况，就是好多相同的数挨着，欸，那不就是特殊性质吗。 
那我直接预处理，连着的数，把nxt都直接设成最后一个 
11.28
写出了一个非常神秘的代码。时间复杂度不会证。
似乎容易被1 2 1 2 1 2 1 2之类的数据卡掉。
其他情况下好像跑的挺快？因为如果块小，跳的就多；块大，idx就小。
怎么证明时间复杂度呢？ 
*/
