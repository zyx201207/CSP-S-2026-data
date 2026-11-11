#include <bits/stdc++.h>
using namespace std;
int n;
string s = "";
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		long long a;
		string c;
		cin >> a >> c;
		for(int j = 1;j <= a;j++){
			s = s + c;
		}
	}
	long long q = s.size();
	long long cnt = 0;
	long long mid = q / 2;
	for(long long i = 0;i < mid;i++){
		if(s[i] != s[q-i-1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
