#include<bits/stdc++.h>
using namespace std;
int ans[300005] , a[500005];
stack<int> s;
int main() {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	map<int , bool> t;
	for(int i = 1; i <= n; i++)
	cin >> a[i];
	for(int i = 1; i <= n; i++){
		t.clear();
		for(int j = i; j <= n; j++) {
			if(t[a[j]]) {
				while(s.top() != a[j]) {
					t[s.top()] = 0;
					s.pop();
				}
				s.pop();
			}
			t[a[j]] = 1;
			s.push(a[j]);
		}
		for(auto i : t)
			ans[i.first] += i.second;
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << " ";
} 
