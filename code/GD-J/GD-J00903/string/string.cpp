#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, a;
long long cnt = 0;
char c;
string s = "";
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while(n--){
		cin >> a >> c;
		for(long long i = 1; i <= a; i++) s += c;
	}
	for(long long i = 0; i < s.size() / 2 + 1; i++){
		if(s[i] != s[s.size() - 1 - i]){
			cnt++;
			s[i] = s[s.size() - 1 - i];
		}
	}
	cout << cnt;
	return 0;
}
