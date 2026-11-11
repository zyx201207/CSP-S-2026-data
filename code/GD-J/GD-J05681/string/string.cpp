#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	while(n--){
		char c;
		long long num;
		cin >> num >> c;
		for (long long i = 1; i <= num; i++){
			s += c;
		}
	}
	int cnt = 0;
	for (int i = 0, j = s.size()-1; i <= j; i++, j--){
		if (s[i] != s[j]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
