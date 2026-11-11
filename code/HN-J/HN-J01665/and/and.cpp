#include<bits/stdc++.h>
using namespace std;
int n, m;
string s[200004];
string solve_one(int x){
	string as;
	while (x > 0){
		as += char((x % 2) + 48);
		x /= 2;
	}
	return as;
}
bool cmp(string x, string y){
	int r = x.size() - 1;
	int x_ans = 0, y_ans = 0;
	while (r > 0) {
		if (x[r] == '1') x_ans += 1;
		if (y[r] == '1') y_ans += 1; 
		r -= 1;
	}
	return x_ans > y_ans;
}
string ands(string a, string b){
	int lenth = max(a.size(), b.size());
	string r;
	for (int i = 0;i < lenth;i++){
		if(a[i] == b[i] && a[i] == '1') r += '1';
		else r += '0';
	}
	return r;
}
long long cf(int a, int b){
	if (b == 0) return 1;
	else if (b == 1) return a;
	else return a + cf(a, b - 1);
}
int solve_two(string x){
	int r = 0;
	for (int i = 0;i < x.size();i++){
		r += cf(2, i) * int(x[i] - 48);
	}
	return r;
} 
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
    	int a;
		cin >> a;
		s[i] = solve_one(a); 
	}
	sort (s + 1, s + n + 1, cmp);
	string r = s[1];
	for (int i = 2;i <= m;i++){
		r = ands(r, s[i]);
	}
	cout << solve_two(r) << endl;
	return 0;
} 
