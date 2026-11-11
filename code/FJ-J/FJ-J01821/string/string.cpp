#include <bits/stdc++.h>
using namespace std;
int a[200010] = {};
char c[200010] = {};
bool w(string b){
	for (long long i = 0 ; i <= b.size() / 2; i++)
		if (b[i] != b[b.size() - i - 1]) return false;
	return true;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,num = 0;
	string b = "";
	cin >> n;
	for (long long i = 1 ; i <= n ; i++) {
		cin >> a[i] >> c[i];
		for (long long j = 1 ; j <= a[i] ; j++) b += c[i];
	}
	bool ok = true;
	for (long long i = 2 ; i <= n ; i++)
		if (c[1] != c[i]) ok = false;
	if (ok){
		cout << 0; 
		return 0;
	}
	if (w(b)) {
		cout << 0;
		return 0;	
	}
	long long now = 1;
	while(true){
		long long max_num = 0, now_num = 0;
		char max_char = c[now];
		for (long long i = 0 ; i < b.size() ; i++)
			if (b[i] == c[now]) now_num++;	
		if (now_num > max_num){
			max_num = now_num;
			max_char = c[now];
			}
		for (long long i = 0 ; i <= b.size() / 2; i++){
			if (b[i] == max_char && b[b.size() - i - 1] != max_char){
				num++;
				b[b.size() - i - 1] = max_char;
			}
		}
		if (w(b)) break;
	}
	cout << num << endl;
	return 0;
}