/*
首先最终选定的数一定是原序列的数？	
一定是先决定哪些数要变化，然后挑一个中间值。可以
证明，这个中间值一定可以调整为原序列的数。
排序，钦定选哪个数作为调整值。此时选中的数是一个区间。
形式化的，假设区间的范围是 [l,r]，那么有：

感觉复杂了，我们可以维护出绝对值。
然后就是找包含 i 的最大的区间，区间和不超过 m。
左边不断增加，右边不断减少，所以可以双指针。
感觉还是很复杂。
至少 l 是一直往右的吧？

这是个区间选址问题，或许我们应该钦定区间的左端点。
不论何时，选择 l+len/2 那个点一定是最优的。
所以我们钦定 l，二分 len 就好了吧。判断可以 O(1) 的。

我靠，怎么只能增加啊。
那这样直接钦定就好了啊，双指针左端点。
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long ;
using ii = __int128;
using vl = vector<ll>;
using vi = vector<int>;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n; ll m; cin>>n>>m;
	vl a(n+5);
	for(int i=1;i<=n;i++) cin>>a[i];

	sort(a.begin()+1,a.begin()+1+n);
	int mx=0,l=1;
	ll sum=0;
	for(int r=1;r<=n;r++)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		while(l<=r&&sum>m) sum-=(a[r]-a[l++]);
		mx=max(mx,r-l+1);
		// cerr<<l<<" "<<r<<" "<<sum<<"\n";
	}
	cout<<mx;
}
// g++ crystal.cpp -o crystal -std=c++14 -Wall -Wextra -O2 -Wshadow && .\crystal && fc crystal.out crystal.ans