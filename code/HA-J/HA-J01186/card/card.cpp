#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, m, t = 1;
int a[N];
int qu[N], ans[300010];
stack<int> s;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	while(t <= n){
		for(int i = t;i <= n;i++){
			qu[a[i]]++;
			if(qu[a[i]] > 1){
				while(s.top() != a[i]){
					qu[s.top()] = 0;
					s.pop();
				}
				qu[s.top()] = 0;
				s.pop();
				qu[a[i]]++;
			}
			s.push(a[i]);
		}
		for(int i = 1;i <= m;i++){
			ans[i] += qu[i];
			qu[i] = 0;
		}
		while(!s.empty()){
			s.pop();
		}
		t++;
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
