#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, vis[N], a[N];
void f(int x) {
	queue<int> q, q2;
	q.push(a[x]);
	for(int i = x + 1; i < n; i++) {
		bool flag = false;
		while(!q.empty()) {
			int num = q.front(); q.pop();
			if(num != a[i]) q2.push(num);
			else{
				flag = true;
				break;
			}
		}
		if(!flag) q2.push(a[i]);
		q = q2;
		while(!q2.empty()){
			vis[q2.front()]++;
			q2.pop();
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) f(i);
	for(int i = 1; i <= m; i++) cout << vis[i] << " ";
	return 0;
}
