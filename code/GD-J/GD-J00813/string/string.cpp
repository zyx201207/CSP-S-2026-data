#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){
		long long a;
		string c;
		cin >> a >> c;
		for (int i = 1;i <= a;i++){
			s += c;
		}
	}
	long long  ans = 0;
	for (int i = 0;i < s.size()/2;i++){
		if (s[i] != s[s.size()-i-1] && s[i] != ' ' && s[s.size()-i-1] != ' '){
			ans++;
			s[s.size()-i-1] = s[i];
		}
	}
	cout << ans;
	return 0;
}
