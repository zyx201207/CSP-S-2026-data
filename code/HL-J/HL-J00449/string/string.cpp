#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ull n;
	ull ans = 0;
	cin >> n;
	string s = "";
	for (ull i = 1; i <= n; i++){
		ull a;
		char c;
		cin >> a >> c;
		for (ull j = 1; j <= a; j++){
			s += c;
		}
	}
//	cout << s << endl;
	for (ull i = 0; i <= s.size()/2-1; i++){
		if(s[i] != s[s.size() - i - 1]) ans++;
//		cout << s[i] << " " << s[s.size() - i - 1] << " " << ans << endl;
	}
//	cout << s.size() << endl;
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

