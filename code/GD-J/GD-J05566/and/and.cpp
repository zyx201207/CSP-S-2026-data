#include <bits/stdc++.h>
using namespace std;
vector <int> q;
int max_cnt = 0;
void f(int m, vector <int> v){
	if (q.size() == m){
		int cnt = INT_MAX;
		for (int y : q){
			cnt = cnt & y;
		}
		max_cnt = max(cnt, max_cnt);
		return;
	}
	for (int x : v){
		q.push_back(x);
		f(m - 1, v);
		q.pop_back();
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <int> v(n, 0);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	f(m, v);
	cout << max_cnt << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
