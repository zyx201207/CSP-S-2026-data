#include<bits/stdc++.h>
#define ll long long
using namespace std;
void read(ll x){
	cin >> x;
	return;
}
ll t, n, ans, d, a[2000005], deg[2000005], sdeg[2000005], ssdeg[2000005];
struct tree{
	ll l, r, id, sum, lazy;
}qwq[8000005];
void pushup(ll id){
	qwq[id].sum = qwq[id * 2].sum + qwq[id * 2 + 1].sum;
}
void pushdown(ll id){
	qwq[id * 2].lazy += qwq[id].lazy;
	qwq[id * 2].sum += qwq[id].lazy * (qwq[id * 2].r - qwq[id * 2].l + 1);
	qwq[id * 2 + 1].lazy += qwq[id].lazy;
	qwq[id * 2 + 1].sum += qwq[id].lazy * (qwq[id * 2 + 1].r - qwq[id * 2 + 1].l + 1);
	qwq[id].lazy = 0;
}
void build(ll id, ll l, ll r){
	qwq[id].l = l;
	qwq[id].r = r;
	qwq[id].id = id;
	qwq[id].lazy = 0;
	qwq[id].sum;
	if(l == r){
		return;
	}
	ll mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
} 
ll search(ll id, ll l, ll r){
	if(qwq[id].l >= l && qwq[id].r <= r){
		return qwq[id].sum;
	}
	pushdown(id);
	ll mid = (qwq[id].l + qwq[id].r) / 2, ans = 0;
	if(l <= mid){
		ans += search(id * 2, l, r);
	}
	if(r > mid){
		ans += search(id * 2 + 1, l, r);
	}
	return ans;
}
void update(ll id, ll l, ll r){
	if(qwq[id].l >= l && qwq[id].r <= r){
		qwq[id].sum += qwq[id].r - qwq[id].l + 1;
		qwq[id].lazy++;
		return;
	}
	pushdown(id);
	ll mid = (qwq[id].l + qwq[id].r) / 2, ans = 0;
	if(l <= mid){
		update(id * 2, l, r);
	}
	if(r > mid){
		update(id * 2 + 1, l, r);
	}
	pushup(id);
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> t >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		if(d / (a[2] - a[1] + 1) != 2){
			cout << 0 <<endl;
		}
		else{
			cout << n - 3 <<endl;
		}
	}
	return (0 - 0);
}
//15:49 会了前40分。
//16:01 开始思考一下特殊性质。虽然但是，老实拼部分分，很无聊吧！ 
//16:08 吃东西去了，会了特殊性质A。
//16:12 这么说，如果能把特殊性质全部爆掉的话，能拼出300+，有概率能进WC？！ 
//16:16 思考获得了一些进展，但是复杂度并没有被优化。 
//16:28 正解可能？？？？？？？
//16:30 哦考试结束还有2h啊我以为只有1h了
//16:44 没有什么进展。旁边小朋友怎么在斗笔。 
//16:47 好消息：会了；坏消息：好像要线段树。先把T4暴力写了。
//16:56 不会写T4暴力，润回来了。 
//17:02 小朋友在连点鼠标。愤怒了。 
//17:28 能不能不要一直自言自语啊？？？ 
//18:25 爆炸了。 

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
