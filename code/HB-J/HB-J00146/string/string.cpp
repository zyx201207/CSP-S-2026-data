#include<bits/stdc++.h>
using namespace std;

unsigned long long n, a[100000000], ma = -1;
char c[10000000];
string s;

bool check(string s){
	bool f = 1;
	unsigned long long num;
	if (s.size() % 2 == 0){
		num = s.size() / 2;
	} else{
		num = s.size() / 2 + 1;
	}
	for (unsigned long long i = 0; i < num; i++){
		if (s[i] != s[s.size() - i - 1]){
			f = 0;
		}
	}
	if (f == 1){
		return true;
	}
	return false;
}
unsigned long long num, cnt = 0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    bool f = 1;
    cin >> n;
    for (unsigned long long i = 1; i <= n; i++){
		cin >> a[i];
		cin >> c[i];
		ma = max(ma, a[i]);
	}
	for (unsigned long long i = 1; i <= n; i++){
		 for (unsigned long long j = 1; j <= a[i]; j++){
			 s += c[i];
		 }
	}
	for (int i = 1; i < n; i++){
		if (a[i] != a[i + 1]){
			f = 0;
		}
	}
	if (check(s)){
		cout << 0;
		return 0;
	}
	if (s.size() % 2 == 0){
		num = s.size() / 2;
	} else{
		num = s.size() / 2 + 1;
	}
	for (unsigned long long i = 0; i < num; i++){
		if (s[i] != s[s.size() - i - 1]){
			cnt++;
		}
	}
	cout << cnt;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
