#include <bits/stdc++.h>
using namespace std;
const long long N = 2e8 + 1;
int n;
int x, t;
long long sum;
char c;
char s[N];
int fun(char s1[N]){
	int ans = 0;
	for(long long i = 1;i <= sum / 2;i++){
		if(s1[i] != s1[sum + 1 - i]){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x >> c;
		sum += x;
		for(int j = 1;j <= x;j++){
			t++;
			s[t] = c;
		}
	}
	cout << fun(s);
	return 0;
}
