#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;

int n, m;
int a[200005];
//long long t[35];
long long ans;

string itoB(int n){
	string s = "";
	while (n != 0){
		s += (n%2 + '0');
		n /= 2;
	}
	return s;
} 

int Btoi(string s){
	long long t = 1;
	int n = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '1'){
			n += t;
		}
		t *= 2;
	}
	return n;
}

int fand(int a, int b){
	string sa = itoB(a), sb = itoB(b);
	int c_s = min(sa.size(), sb.size());
	string sc = "";
	for (int i = 0; i < c_s; i++){
		if (sa[i] == '1' && sb[i] == '1'){
			sc += "1";
		}
		else sc += "0";
	} 
	return Btoi(sc);
}

void dfs(int p, int cnt, long long sum){
	if (p > n && cnt < m) return ;
	if (cnt == m){
		ans = max(sum, ans);
		return ;
	}
	dfs(p+1, cnt+1, (sum == -1?a[p] : fand(sum,a[p])));
	dfs(p+1, cnt, sum); 
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.ans", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
//	t[0] = 1;
//	for (int i = 1; i <= 30; i++){
//		t[i] = t[i-1] * 2;
//	}
	dfs(1, 0, -1);
	
//	sort(a + 1, a + n + 1, greater<int>());
	
//	ans = a[1];
//	for (int i = 1; i <= m; i++){
//		ans = fand(ans, a[i]);
//	}
	cout << ans;
	return 0;
}
