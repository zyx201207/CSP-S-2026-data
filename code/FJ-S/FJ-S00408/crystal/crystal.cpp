#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
bool flag = true;
long long ans = 0, num, a[N];
long long fun(long long temp){
	priority_queue<long long, vector<long long>, greater<long long> > pq;
	for(int i = 1; i <= n; i++){
		if(a[i] <= temp){
			pq.push(temp - a[i]);
		}
	}
	long long tempm = m, res = 0;
	while(!pq.empty()){
		long long i = pq.top();
		pq.pop();
		if(i <= tempm){
			res++;
			tempm -= i;
		}else{
			break;
		}
	}
	return res;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%lld", &a[1]);
	for(int i = 2; i <= n; i++){
		scanf("%lld", &a[i]);
		if(a[i] - a[i-1] != a[2] - a[1]) flag = false;
	}
	if(flag){
		if(a[2] - a[1] == 0){
			cout << n;
			return 0;
		}
		long long gc = max(a[2] - a[1], a[1] - a[2]);
		long long num = gc;
		int cnt = 1;
		while(true){
			if(m < num) break;
			m -= num;
			num += gc;
			cnt++;
		}
		cout << cnt;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		long long num = fun(a[i]);
		ans = max(ans, num);
	}
	cout << ans;
	return 0;
}
