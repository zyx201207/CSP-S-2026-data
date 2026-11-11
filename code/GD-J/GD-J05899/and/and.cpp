#include<bits/stdc++.h>
using namespace std;
struct num{
	int x;
	int cn;
}a[200010];
bool cmp(const num& o, const num& p){
	if(o.cn != p.cn) return o.cn > p.cn;
	return o.x > p.x;
}
string tentotwo(int n){
	string s; 
	while(n > 0){
		s += (n % 2) + '0';
		n /= 2;
	}
	return s;
}
int count_1(string s){
	int cnt = 0;
	for(size_t i = 0; i < s.size(); i++) if(s[i] == '1') cnt++;
	return cnt;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x;
		a[i].cn = count_1(tentotwo(a[i].x));
	}
	if(m == 1){
		int maxx = -1;
		for(int i = 1; i <= n; i++) maxx = max(maxx, a[i].x);
		cout << maxx;
	}else if(m == n){
		int ans = a[1].x;
	    for(int i = 2; i <= n; i++) ans &= a[i].x;
	    cout << ans;
	}else{
		sort(a + 1, a + n + 1, cmp);
	    int ans = a[1].x;
	    for(int i = 2; i <= m; i++) ans &= a[i].x;
	    cout << ans;
	}
	return 0;
}
