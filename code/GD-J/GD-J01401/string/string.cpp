#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long ans = 0;
	string s = "";
	for(int i = 0;i < n;i++){
		long long a;
		char c;
		cin >> a >> c;
		for(long long i = 0;i < a;i++){
			s += c;
		}
	}
	for(long long i = 0;i < s.length()/2;i++){
		if(s[i] != s[s.length()-1-i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
