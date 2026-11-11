#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
string s = "";
int n;
int f(string s){
	int cnt = 0;
	for (int i = 0; i < s.size(); i ++){
		if (s[i] != s[s.size()-i-1]){
			cnt ++;
			s[s.size()-i-1] = s[i];
		}
	}
	return cnt;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j ++){
			s += c[i];
		}
	}
	cout << f(s) << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
