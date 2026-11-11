#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> Pii;

const int N = 2e6;
int C, T, n;
LL d;
LL x[N+5];
int pre[N+5], nxt[N+5];
//int dg[N+5], ndu[N*15 + 5];
//ULL hpos[N+5];
//unordered_map<ULL, int> mp;

int BFS(int st) {
	static int dis[N+5], f[N+5], que[N+5];
	fill(dis + st, dis + n + 1, 1e9);
	dis[st] = 0;
	int l = 1, r = 0;
	que[++r] = st;
	f[st] = 1;
	while (l <= r) {
		int fr = que[l++];
		for (int i = fr+1; i <= nxt[fr]; i++) {
			if (dis[i] > dis[fr]+1) dis[i] = dis[fr]+1, f[i] = 0, que[++r] = i;
			if (dis[i] == dis[fr]+1) f[i] += f[fr];
		}
	}
	int res = 0;
	for (int i = st; i <= n; i++) res += f[i] == 2;
	return res;
}

//void Upd(int i, int edp) {
//	ULL hsum = 0;
//	for (int j = pre[i]; j > edp; j = pre[j]) {
//		hsum ^= hpos[j];
//		if (j == pre[j]) break;
//	}
//	for (int j = pre[i]; j > edp; j = pre[j]) {
//		cerr << "del" << i << ',' << j << ' ';
//		if (j > 1) mp[hsum ^ hpos[j] ^ hpos[j-1]]--;
//		if (j < n) mp[hsum ^ hpos[j] ^ hpos[j+1]]--;
//		if (j == pre[j]) break;
//	}
//	for (int j = pre[i]; j > 1; j = pre[j]) {
//		hsum ^= hpos[j];
//		if (j == edp || j == pre[j]) break;
//	}
//	for (int j = pre[i]; j > 1; j = pre[j]) {
//		cerr << "ins" << i << ',' << j << ' ';
//		if (j > 1) mp[hsum ^ hpos[j] ^ hpos[j-1]]++;
//		if (j < n) mp[hsum ^ hpos[j] ^ hpos[j+1]]++;
//		if (j == edp || j == pre[j]) break;
//	}
//}

bool subA() {
	LL cd = x[2] - x[1];
	for (int i = 3; i <= n; i++) {
		if (x[i] - x[i-1] != cd) return false;
	}
	return true;
}

void work() {
//	mp.clear();
	LL res = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n && x[j] - x[i] <= d) j++;
		nxt[i] = j-1;
	}
	for (int i = n, j = n; i; i--) {
		while (j && x[i] - x[j] <= d) j--;
		pre[i] = j+1; 
	}
	
	if (subA()) {
		int ds = nxt[1] - 1;
		if (ds <= 1 || nxt[1] == n) return void(cout << "0\n");
		for (int i = 1; i <= n-ds*2+1; i++) {
			int pos = i+ds*2-1;
			res += nxt[i] - pre[pos] == 1;
		}
		cout << res << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++) res += BFS(i);
//	cerr << T;
	
//	fill(dg + 1, dg + n+1 + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		for (int j = pre[i]; ; j = pre[j]) {
//			dg[j]++;
//			if (j == 1 || j == pre[j]) break;
//		}
//	}
//	for (int i = 1; i <= n; i++) dg[i+1] += dg[i];
//	for (int i = 1; i <= n; i++) {
//		for (int j = pre[i]; ; j = pre[j]) {
//			ndu[dg[j]--] = i;
//			if (j == 1 || j == pre[j]) break;
//		}
//	}
//	
//	for (int i = n; i >= 1; i--) {
//		ULL hsum = hpos[nxt[i]];
//		for (int j = nxt[i]; j < n; hsum ^= hpos[j = nxt[j]]) {
//			cerr << "qry" << i << ',' << j << ' ';
//			res += mp[hsum];
//			if (j == nxt[j]) break;
//		}
//		for (int j = dg[i+1]; j > dg[i]; j--) Upd(ndu[j], i);
//	}
	cout << res << '\n';
}

int main() {
//	cout << (sizeof(C) + sizeof(T) + sizeof(n) + sizeof(d) + sizeof(x) + sizeof(pre) + sizeof(nxt) + 
//		sizeof(dg) + sizeof(ndu) + sizeof(hpos)) / 1048576.0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	mt19937_64 gen(time(0));
//	for (int i = 1; i <= N; i++) hpos[i] = gen();
	cin >> C >> T;
	while (T--) work();
	return 0;
}
/*
感觉变成 CSPJ2024 了，秒完 T1T2 看到 T3 乱想乱写去了。
我居然没想到连边广搜，然后有 24 分。
然后猜结论。
观察 A，发现答案是不多的，在跳了两次且没有刚好跳两次的区间，而且仅有一个数！
我突然想起了我初二是做过的一道题，那道题是什么从前和从后都跑一遍贪心，这道题也很同理。
如果我们前后跑一遍误差的乘积超过 2，显然是不行的。
上面那个有点假。
又手模了一下，发现出现两个错开的就是假的，于是这道题就变成了从前往后贪心扫方案，两者之间有且仅能有一个数错开。
那特殊性质 C 不随便做，直接搞一个异或，不计首尾删掉一个数做。那我有 72 了。是不是 [216, 272]。
然后 B 同理。
不对头还是要哈希，然后看是否为相邻两个位置。
我这么菜，都要退役了，一天天地摆，显然不可能拿到一等的（线保守估计 260）。T2，T3 而且还有可能是假算。
刚刚突然想到固定完 l 以后 r 很难求，但我不计首尾了，吓死我了，这种做法需要在修改的时候记值。 
没调出来，不想学了。 
*/
