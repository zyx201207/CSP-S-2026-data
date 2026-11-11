#include<bits/stdc++.h>
#define endl '\n'
#define debug() cout << "qwq" << endl;
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N], c[N];

bool check(int k){
	int ans = 1e18, cnt = 0, tp = 0;
	
	for(int i = 1; i <= n; i ++){ 
		if(i < k){
			cnt += i * c[i];
			tp += c[i];
		}else{
			//cout << k << " " << i << " " << tp << " " << cnt << endl; 
			ans = min(ans, cnt);
			cnt -= tp;
			tp -= c[i - k + 1];
			cnt += (k - 1) * c[i];
			tp += c[i];
		}
	} 
	if(ans <= m) return true;
	return false;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i ++) c[i] = a[i + 1] - a[i];
	int l = 1, r = n, mid;
	while(l < r){
		mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	
	return 0;
}
/*
//freopen("crystal4.in");
关注luogu 554576 谢谢喵

首先我们很显然的知道，最后选择用来合并的水晶一定是排序后连续的。
这是显然的吧。应该吧。嗯对，没问题。
然后怎么做。
好像可以二分答案一下？
不对，好像不是很好统计所需要的操作次数。 
*/
