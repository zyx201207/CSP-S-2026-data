#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, sum;
vector<bool> b;
stack<int> s;

int main(){
	freopen("card6.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	a.resize(n + 1), sum.resize(m + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		b.assign(m + 1, false);
		for(int j = i; j <= n; j++){
			if(b[a[j]]){
				while(s.top() != a[j]){
					b[s.top()] = false;
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				b[a[j]] = true;
			}
		}
		for(int j = 1; j <= m; j++){
			if(b[j]){
				sum[j]++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << sum[i] << ' ';
	}
	cout << '\n';
	return 0;
}
