#include<bits/stdc++.h>
#define Crystal_poem return
#define code 0
#define ll long long
#define pair pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define pb push_back
using namespace std;
int const N = 5e5 + 5;
int n;
ll a[N], m; 
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll sum = 0; int ans = 0;
	for(int l = 1, r = 1; r <= n; r++) {
		sum += 1ll * (r - l) * (a[r] - a[r - 1]);
		while(sum > m) {
			sum -= (a[r] - a[l]); l ++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	Crystal_poem code;
} 
/*
额
首先答案应该是有单调性的
但是你不能二分这个吧
欸应该是可以的吧，我二分那个多少个数
然后你肯定最优是排完序之后挨一起的对不对
然后你又有那个什么定理啊，反正就是你搞中位数肯定是最优的
那你能不能预处理出就是用前缀和去算我 k 个数放一起的需要的步数
额应该是可以的
就是你1，2，3，4，全变成2的话就是 首先3 + 4 - 2 * 2
好像没有问题 
*/
