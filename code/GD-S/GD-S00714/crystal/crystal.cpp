#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;

int n,m;
std::array<int,MAX> a;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin.tie(0) -> sync_with_stdio(0);

	std::cin >> n >> m;
	for(int i = 1;i <= n;i++)
		std::cin >> a[i];
	std::sort(a.begin() + 1,a.begin() + n + 1);

	int ans = 1;
	ll sum = 0;
	std::deque<ll> q;
	q.push_back(a[1]);
	for(int i = 2;i <= n;i++) {
		sum += q.size() * (a[i] - q.back());
		while(sum > m && !q.empty()){
			sum -= a[i] - q.front();
			q.pop_front();
		}
		// 队内的元素加上新加进来的
		ans = std::max(ans,int(q.size() + 1));
		q.push_back(a[i]);
	}
	std::cout << ans << '\n';
	return 0;
}
/*
给定一个数列，每次操作可以使元素加一，求最多可以使得多少个元素相同
最终的元素必然是原数列中的某一个，
这样一定是不劣的，不然我完全有机会让那个最大的元素的操作分给其他元素
那么正解就出来了：
把原数列排序，枚举原数组，设这个元素为 a_i
那么前面 x 个元素与它的差之和如果小于 m，那么 x 就是合法的，我们希望令这个 x 最小
这个可以单调队列维护？
也不能算是单调队列，总之就是一个队列
*/