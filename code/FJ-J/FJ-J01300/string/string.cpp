#include <bits/stdc++.h>
using namespace std;

bool bo(char c1, char c2){
	return !(c1 == c2);
}
int main(){
	freopen("string.in", r, stdin);
	freopen("string.out", w, stdout);
	int n;
	int ans = 0;
	bool b = 0, b1 = 1;
	cin >> n;
	long long ll[200005] = {0};
	string s;
	for (int i = 0; i < n; ++i){
		cin >> ll[i] >> s[i];
	}
	for(int i = 0; i < s.size() - 1; ++i){
		if (s[i] != s[i + 1]){
			b = 1;
		}
	}
	for(int i = 0; i < s.size() - 1; ++i){
		if (ll[i] != 1){
			b1 = 0;
		}
	}
	if(n == 1){
		cout << 0;
		return 0;
	}if(!b){
		cout << 0;
		return 0;
	}if(b1){
		for(int i = 0; i < (s.size())/2; ++i){
			if(bo(s[i], s[s.size() - 1 - i])){
				ans += 1;
			}
}
}
	cout << ans;
	return 0;
} 
