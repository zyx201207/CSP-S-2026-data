#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long ans, ls, rs;
deque<pair<int, char>> l, r;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i]; j++){
			s.push_back(c[i]);
		}
	}
	for(int i = 0, j = s.size()-1; i < j; i++, j--){
		if(s[i] != s[j]){
			ans++;
		}
	}
	/*for(int i = 1, j = n; i <= j; i++, j--){
		if(i == j){
			long long sum = ls+rs;
			long long num1 = rs-(sum-a[i])/2, num2 = ls-(sum-a[j])/2;
			l.push_back(num1);
			r.push_back(num2);
			ls += num1, rs += num2;
		}
		else{
			l.push_back({a[i], c[i]});
			r.push_back({a[j], c[j]});
			ls += a[i];
			rs += a[j];
		}
		if(l[0].second != r[0].second){
			if(l[0].first < r[0].first){
				r[0].first -= l[0].first;
				ans += l[0].first;
				ls -= l[0].first, rs -= r[0].first;
				l.pop_front();
			}
			else if(l[0].first > r[0].first){
				l[0].first -= r[0].first;
				ans += r[0].first;
				ls -= l[0].first, rs -= r[0].first;
				r.pop_front();
			}
			else{
				ans += l[0].first;
				ls -= l[0].first, rs -= r[0].first;
				l.pop_front();
				r.pop_front();
			}
		}
		else{
			if(l[0].first < r[0].first){
				r[0].first -= l[0].first;
				ls -= l[0].first, rs -= r[0].first;
				l.pop_front();
			}
			else if(l[0].first > r[0].first){
				l[0].first -= r[0].first;
				ls -= l[0].first, rs -= r[0].first;
				r.pop_front();
			}
			else{
				ls -= l[0].first, rs -= r[0].first;
				l.pop_front();
				r.pop_front();
			}
		}
	}*/
	cout << ans;
	return 0;
}
