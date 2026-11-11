#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 7;
int n, m;
int a[maxn], b[maxn], ans[maxn];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) b[j] = 0;
		stack<int> s;
		for(int k = i; k <= n; k++){
			if(b[a[k]] > 0){
				while(!s.empty()){
					if(s.top() == a[k]){
						b[s.top()]--;
						s.pop();
						break;
					} else {
						b[s.top()]--;
						s.pop();
					}
				}
			}
			s.push(a[k]);
			b[a[k]]++;
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
