#include <bits/stdc++.h>
using namespace std;
string s;
string h;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long a, cnt = 0, re = 0;
	char c;
	for(int i = 1; i <= n; i++){
		cin >> a >> c;
		cnt += a;
		for(long long j = 1; j <= a; j++){
			s += c;
		}
	}
	
	for(int i = cnt-1; i >= 0; i--){
		h += s[i];
	}
	if(h==s){
		cout << "0";
		return 0;
	}
	for(int i = 0; i <= cnt/2; i++){
		if(s[i]!=s[cnt-i]){
			re++;
			s[cnt-i] = s[i];
		}
	}
	cout << re;
	return 0;
}
