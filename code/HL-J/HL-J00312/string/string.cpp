#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out",wr",stdout);
	int n;
	cin >> n;
	string s = "";
	while(n--){
		int sk;
		char d;
		cin >> sk >> d;
		while(sk--){
			s += d;
		}
	}
	string r = s;
	int ans = 0;
	reverse(r.begin(),r.end());
	for(int i = 0;i < s.size();i++){
		if (s[i] != r[i]){
			s[i] = r[i];
			r[r.size() - 1 - i] = s[i];
			ans++;
			if (s == r) {
				cout << ans;
				return 0;
			}
		}
	}
	cout << ans;
}
