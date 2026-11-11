#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	ll ans = 0;
	cin >> n;
	deque<pair<int, char> > q;
	for(int i = 1; i <= n; i++){
		int a;
		char c;
		cin >> a >> c;
		q.push_back({a, c});
	}
	while(q.size() > 1){
		int a = q.front().first, b = q.back().first;
		char x = q.front().second, y = q.back().second;
		if(x == y){
			q.pop_front();
			q.pop_back();
			if(a > b) q.push_front({a - b, x});
			else if(a < b) q.push_back({b - a, x});
		}else{
			q.pop_front();
			q.pop_back();
			if(a > b){
				ans += b;
				q.push_front({a - b, x});
			}else if(a < b){
				ans += a;
				q.push_back({b - a, y});
			}else ans += a;
		}
	}
	cout << ans;
	return 0;
}
