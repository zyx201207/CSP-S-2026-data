#include<bits/stdc++.h>
using namespace std;
int n, a[200005], ans = 0, st[INT_MAX], s = 0;
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);	
	cin >> n;
	int t = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> c[i];
		s += a[i];
		for(int j = 0; j < a[i]; ++j){
			st[t] = c[i];
			++t;
		}
	}
	for(int i = 0; i < s/2; ++i){
		if(st[i] != st[s-i+1]){
			st[s-i+1] = st[i];
			++ans;
		}
	}
	cout << ans;
	return 0;
}
