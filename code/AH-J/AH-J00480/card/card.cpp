#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
//我了小猫钓鱼
//暴力n^2 
int n, m;
int a[N], ct[N], cnt[N], fA = 1;
void solve1(){
	for(int i = 1; i <= n; i ++){
		memset(cnt, 0, sizeof cnt);
		stack<int> q, p;
		for(int j = i; j <= n; j ++){
			if(cnt[a[j]]){
				while(!q.empty()){
					if(q.top() == a[j]){
						cnt[q.top()] --;
						q.pop();
						break;
					}
					cnt[q.top()] --;
					q.pop();
				}
			}

			cnt[a[j]] ++;
			q.push(a[j]);	
		}
		while(!q.empty()){
			ct[q.top()] ++;
			q.pop();
		}
	}
	for(int i = 1; i <= m; i ++) cout << ct[i] << ' ';
}
void solve2(){
	//当且仅当a_i不被别的数所包含，a_i可以留
	if(m == 1){
		cout << n;
		return ;
	}
	if(a[n] == 1) {
		int t = 0;
		for(int i = 1; i <= n; i ++) {
			if(a[i] == 2) t ++;
		}
		cout << n << ' ' << t;
	}
	if(a[n] == 2){
		int t = 0;
		for(int i = 1; i <= n; i ++) {
			if(a[i] == 1) t ++;
		}
		cout << t << ' ' << n;
	}
}
void solve3(){
	for(int i = 1; i <= n; i ++){
		if(a[i] != a[i - 1]) cout << i - 1;
	}
	cout << n;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] < a[i - 1]) fA = 0;
	}
	if(n <= 5000 && m <= 3000) solve1();
	else if(m <= 2) solve2();
	else if(fA) solve3();
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

1 1 1 2 2 2 3 3 3 4

*/
