//GZ-J00021 贵阳市第一中学  郑淇予
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ll long long
#define lowbit(p) ((p)&-(p))
using namespace std;
const int N = 500005, M = 300005;
int t[N], lst[M], a[N], ans[M];
//区间修改、单点查询 -> 树状差分数组 

void update(int x, int d){
	while(x < N){
		t[x] += d;
		x += lowbit(x);
	}
}

int que(int x){
	int ans = 0;
	while(x > 0){
		ans += t[x];
		x -= lowbit(x);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n){
		cin >> a[i];
		lst[a[i]] = i;
		update(i, 1);
		update(n+1, -1);
	}
	FOR(i, 1, n){
		if(lst[a[i]] <= i)continue;
		int d = que(i);
		update(i, -d);
		update(lst[a[i]], d);
	}
	FOR(i, 1, n){
		int d = que(i);
		ans[a[i]] += d;
	}
	FOR(i, 1, m){
		cout << ans[i];
		if(i < m)cout << ' ';
	}
	return 0;
}
