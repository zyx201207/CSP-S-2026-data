#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int c1, c2;
string s1, s2;

int po(string s){
	int g = 0;
	for (int i = 0;i < s.size();i ++){
		if (s[i] >= '0' && s[i] <= '9'){
			g = g * 10 + s[i] - '0';
		}
		// cout << g << "\n";
	}
	return g;
}

char hk(string s){
	char p;
	for (int i = 0;i < s.size();i ++){
		if (s[i] >= 'A' && s[i] <= 'Z'){
			p = s[i];
		}
	}
	return p;
}

void solve(){
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2){
		cout << "0000\n";
	}else {
		int k = po(s1), h = po(s2);
		char ks = hk(s1), hs = hk(s2);
		cout << "1";
		// cout << (ks >= 'A' && ks <= 'C') << " " << (hs >= 'A' && hs <= 'C') << "\n";
		if (k == h){
			cout << "1";
			if ((ks >= 'A' && ks <= 'C' && hs >= 'A' && hs <= 'C') || (ks >= 'D' && ks <= 'F' && hs >= 'D' && hs <= 'F')) cout << "1";
			else cout << "0";
			if (k == h && ((ks == hs + 1 && hs != 'C') || (hs == ks + 1 && ks != 'C'))) cout << "1";
			else cout << "0";
		}
		else cout << "000";
		
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while (t --){
		solve();
	}
	return 0;
	// fclose(stdout);
}

