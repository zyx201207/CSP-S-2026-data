#include <bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , Prefix[500005];
long long getRange(long long x) { return (upper_bound((a + 1) , (a + n + 1) , x) - a - 1); }//查找最大的i，使得a[i]<=x 
long long f(long long x) {
	long long idx = getRange(x); 
	return (idx * x - Prefix[idx]);
}
int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	long long minimum = LLONG_MAX , maximum = LLONG_MIN;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		minimum = min(minimum , a[i]);
		maximum = max(maximum , a[i]);
	}
	sort(a + 1 , a + n + 1); //排序：O(n log n)
	Prefix[0] = 0;
	for(long long i = 1; i <= n; i++) Prefix[i] = Prefix[i - 1] + a[i];
	//查找最大的x，使得λ*x - Prefix[λ]<=m（即：Σ(i=1,λ)(x-a[i])<=m），其中λ=getRange(x)
	long long l = minimum , r = maximum; //确定查找的范围
	while(l <= r) { //二分查找，时间复杂度O(log(n) ^ 2) 
		if((r - l) <= 1) { //避免无效循环，已经缩小到[l,l+1]的范围了 
			goto out_of_search;
		}
		long long mid = ((l + r) / 2);
		long long val = f(mid); //代入x=mid，计算并判断是否小于m 
		if(val > m) r = (mid - 1); //如果大于m，说明这个mid太大了，改为在[l,mid-1]搜索
		else l = mid; //如果满足条件，则在[mid,r]搜索 
	}
	out_of_search:
		long long el = l , er = r; //修正l、r的大小 
		l = min(el , er) , r = max(el , er);
		if((f(l) <= m) && (f(r) <= m)) cout << getRange(r); //都可以，输出较大的 
		else if((f(l) <= m) && (f(r) > m)) cout << getRange(l); //小的可以，大的不行，输出较小的 
		else if((f(l) > m) && (f(r) <= m)) cout << getRange(r); //小的不行，大的可以，输出较大的（极其特殊的情况） 
		else cout << "1"; //极其特殊的情况 
	return 0;
}
