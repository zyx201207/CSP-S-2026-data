#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10;
const int M = 35;
int n, m, maxn, ans;
int b[N], a[N], ptwo[M];
int sum[M], cnt; 
string s[N];
bool vis[N];

int Totwo(int x) {
	vector<char> res;
	int num = 0;
	for(int i = 0 ; i < M; i ++)
		res.push_back('0');
	while(x) {
		int cal = lower_bound(ptwo, ptwo + M, x) - ptwo;
		maxn = max(maxn, cal);
		if(ptwo[cal] > x) cal --;
		res[cal] = '1';
		sum[cal] ++;
		x -= ptwo[cal];
	}
	while(res.back() != '0') res.pop_back();
	for(int i = res.size() - 1; i >= 0; i --) 
		num = num * 10 + (res[i] - '0');	
	return num;
}

signed main() {
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ptwo[0] = 1;
	for(int i = 1; i < M; i ++)
		ptwo[i] = ptwo[i - 1] * 2;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> b[i];
		a[i] = Totwo(b[i]);
		int t = a[i];
		while(t) {
			s[i] += t % 10 + '0';
			t /= 10;
		}
		reverse(s[i].begin(), s[i].end());
	}
	sort(b + 1, b + n + 1, greater<int>());
	sort(a + 1, a + n + 1, greater<int>());
	sort(s + 1, s + n + 1, greater<string>());
	
	for(int l = maxn; l >= 0; l --) {
		if(sum[l] < m) continue;
		cnt = 0;
		for(int i = 1; i <= n; i ++) {		
			if(s[i][s[i].size() - l - 1] == '1') {
				cnt ++;
				vis[i] = true;
			}
			else 
				vis[i] = false;	
		}
		if(cnt == m) {
			bool fir = false;
			for(int i = 1; i <= n; i ++) {
				if(!vis[i]) continue;
				if(!fir) ans = b[i], fir = true;
				else ans = ans & b[i];				
			}
			cout << ans << '\n';
			return 0;
		}
	}
	bool fir = false;
	for(int i = 1; i <= n; i ++) {
		if(!vis[i]) continue;
		if(!fir) ans = b[i], fir = true;
		else ans = ans & b[i];				
	}
	cout << ans << '\n';	
	return 0;
}
