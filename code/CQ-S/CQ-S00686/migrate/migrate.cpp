#include<bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
//
//
//
using namespace std;
inline int read() {
	int sum = 0, f = 0;
	char c = getchar();
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) sum = (sum<<1) + (sum << 3) + c - 48, c = getchar();
	return f ? -sum: sum;
}
const int MX = 2e6 + 10;
int a[MX], Sum[MX];
int d, n, f[MX], sum[MX];
int F[MX], sumf[MX];
int f2[MX],sum2[MX];
void Mem() {
	FOR(i,0,n + 1)
	f[i] = sum[i] = Sum[i] = F[i] = sumf[i] = f2[i] = sum2[i] = 0;
	//清空
}
int B1(int x) {
	//找到以i为结尾能一步到的最远点的位置
//	cout<<x<<"S";
	int l = 1, r = x, mid = (l + r) >> 1ll;
	int ans = x;
	while(l <= r) {
		if((a[x] - a[mid]) <= d) ans = min(ans, mid), r = mid - 1;
		else l = mid + 1;
		mid = (l + r) >> 1ll;
	}
//	cout<<x<<"e\n";
	return ans;
}
int To(int x) {
//	cout<<x<<"S";
	int l = 1, r = x, mid = (l + r) >> 1ll;
	int ans = x;
	while(l <= r) {
		if((a[mid] - a[x]) <= d) ans = max(ans, mid), l = mid + 1;
		else r = mid - 1;
		mid = (l + r) >> 1ll;
	}
//	cout<<x<<"e\n";
	return ans;
}
signed main() {
	/*
	0 1
	5 3
	-3 0 2 3 4
	*/
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c = read(), T = read();
	while(T --) {
		n = read(), d = read();
		FOR(i,1,n) a[i] = read();
		Mem();
		FOR(i,1,n) {
			//计算 i 点的 f[i]
			if(i == n) {
				int a = B1(i);
//				cout<<a<<" sd";
				f[i] = (max(0ll,sum[i - 1] - sum[a])) + (i - a);
				continue;
			}
			int a = B1(i), b = B1(i + 1);
			//
			if(a == b) {
				sum[i] = sum[i - 1] + f[i];
				continue;
			}
//			cout<<i << ' '<< a << " "<< b<<'\n';
			f[i] = (sum[b - 1] - sum[a] + (b - a));
			sum[i] = sum[i - 1] + f[i];
		}

//		FOR(i,1,n) cout<<f[i]<<" ";
//		cout<<"\n";
		//优雅的count
		FOR(i,1,n) {
			//计算长度为 3 以i结尾 且有且仅有俩路径的数量
//			int id = To(i);
//			int t1 = To(id - 1), t2 = To(id - 2);
			int id = B1(i);
			int t1 = B1(id + 1), t2 = B1(id + 2);
//			(t2 - 1) - t1  的所有点都是可以 以i结尾长度为3 且仅有俩路径的点 要注意 会不会有负数
//			t1 == t2
//			if(t2 == t1) continue;
//			cout<<i<<" "<<id<<" "<<t2<<" asdfgh "<<t1<<"\n";
			if(id + 2 > i || t1 == t2) {
				sumf[i] = sumf[i - 1] + F[i];
				continue;
			}
			F[i] = (max(0ll, sumf[(t2 - 1)] - sumf[t1]) + (t2 - t1));
			sumf[i] = sumf[i - 1] + F[i];
//			F[i] 记录的是以 i 结尾 有且仅有俩最短路径且中间可以换的那个点在i前一个的所有点
		}
//		FOR(i,1,n) cout<<F[i] <<" ";
//		cout<<"\n";
		int ans = 0;
		ROF(i,n,1) {
//			把以i为起点的 f[i] 算出来
			int a = To(i), b = To(i + 1);
			f2[i] = (max(0ll, sum2[b - 1] - sum2[a])) + (b - a);
			sum2[i] = sum2[i - 1] + f2[i];
//			cout<<f2[i]<<" "<<F[i]<<"\n";
//			把头和尾巴接在一起 就是F[i] *
			ans += (f2[i] * F[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
双经路线最小长度为3
长度为3的是好求的
枚举一个起点 找到当前起点最远能到达的点记为 id
找到id最远能到的点 记为 to1
再找到id - 1最远能到达的点记为to2
希望起点到终点 这条路径有且仅有 起点 > id > 终点 和 起点 > id - 1 > 终点
所以终点是 id 和 id - 1都能到的点 且 id - 2 到不了的点 这会是一段区间

当长度为4呢
是不是在长度为3的基础上有一个点 A ,A 可以一步到原本的起点却到到不了起点后一个点
或者有一个点可以从终点一步到 却不能从终点后一个点一步到

路径5 6 7 8 9 都是这个道理 都是在原路径上多找一个点接在后面
要算的不就是接着我路径为3的线后面有多上中方案吗

把接尾巴和接开头分开算

f[i] 记以i结尾的最小路径只有一条的数量

算f[i] 就是 i 能被一步到的点 和 i - 1 能被 一步到的点的那段区间内的和

这个也好算了

要把尾巴和头拼在一起就相乘

那第二个问题是如何求以某个点为终点的唯一最短路径数量

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
1 3
0

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

