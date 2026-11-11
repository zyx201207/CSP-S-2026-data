#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;

//string

int n;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	string s = "";
	
	for(int i = 1;i <= n;i++) {
		long long a;
		cin >> a;
		char c;
		cin >> c;
		while(a--) s += c;
	}
	
	long long ans = 0;
	
	int L = s.size();
	if(L % 2) L = L / 2;
	else L = L / 2 - 1;
	
	for(int i = 0;i <= L;i++) {
		if(s[i] != s[s.size() - i - 1]) ans++;
	} cout << ans << '\n';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

