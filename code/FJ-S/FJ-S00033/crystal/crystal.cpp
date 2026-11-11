#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
#define LL long long
const int N = 500005;
int n;
LL a[N], m;
LL use[N];

LL Usg(int i, int j){
	return use[j] - use[i] - (a[j]-a[i]) * (i-1);
}

int Solve(int j){ // 从第j个最多能从哪里开始加 返回 j-i+1; 
	int l = 1, r = j; // 二分查找
	int usg;
	while(l < r){
		int i = (l+r)/2;
		usg = Usg(i, j);
		if(usg == m) { // 正好用完
			return j-i+1; 
		}
		else if(usg < m) { // 还有剩余，可以左移区间
			r = i; // 这里r是有可能为答案的 
		}else l = i+1; // 右移区间 l不可能为答案 
	}
	return j-r+1;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 2; i <= n; i++){
		use[i] = use[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, Solve(i));
	}
	cout << ans << endl;
	return 0;
}
