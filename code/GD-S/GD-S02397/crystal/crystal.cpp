#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, cnt, v;
int sum, maxn;
int a[N];
struct qwe {
	int ai;
	int id;
};
qwe pre[N];
bool cmp(qwe l, qwe r){
	return l.ai < r.ai;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 2;i <= n;i++){
		pre[i].ai = a[i] - a[i - 1];
		pre[i].id = i;
		if(i != 2 && pre[i].ai != pre[i - 1].ai){
			v++;
		}
	}
	if(v == 0){
		while(cnt <= m && sum < n){
			sum++;
			cnt += pre[2].ai * sum;
		}
		cout << sum;
		return 0;
	}
	for(int i = 2;i <= n;i++){
		while(cnt <= m && sum < n){
			sum++;
			cnt += pre[sum + 1].ai * sum;
		}
		maxn = max(sum, maxn);
	}
	cout << maxn;
	return 0;
}

