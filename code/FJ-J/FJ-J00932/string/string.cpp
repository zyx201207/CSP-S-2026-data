#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
int a, x[N];
long long ans;
char c;
string s;
bool cmp(string s){
	int len = s.length();
	for (int i = 0; i < len; ++ i){
		if (s[i] != s[len - i - 1]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	scanf("%d", &n); 
	for (int i = 0; i < n; ++ i){
		cin >> a >> c;
		x[int(c - 97)] = a;
		for (int j = 0; j < a; ++ j){
			s = s + c;
		}
	}
	int len = s.length();
	for (int i = 0; i < len; ++ i){
		if (cmp(s)){
			printf("%d\n", ans);
			return 0;
		}
		if(s[i] != s[len - i - 1]){
			ans ++;
			if (x[int(s[i] - 96)] >= x[int(s[len - 1 - i] - 96)]){
				s[len - i - 1] = s[i];
			}
			else {
				s[i] = s[len - i - 1];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
