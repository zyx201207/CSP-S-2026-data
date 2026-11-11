#include<bits/stdc++.h>
using namespace std;
string s[200005], c;
int n, a, t, ans;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> c;
		for(int j = t + 1; j <= a + t; j++){
			s[j] = c;
		}
		t += a;
	}
	for(int i = 1; i <= t / 2; i++){
		if(s[i] != s[t - i + 1]) ans++;
	}
	cout << ans;
	return 0;
}
