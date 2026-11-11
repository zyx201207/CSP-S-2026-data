#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[200005];
int b[200005];
string s[200005];
char r[25];
int ans;
string change(int x)
{
	int cnt = 0;
	string ss;
	while(x > 0) {
		cnt++;
		int rr = x % 2;
		x /= 2;
		r[cnt] = rr + '0';
	}
	for(int i = cnt; i >= 1; i--) ss += r[i];
	return ss; 
}
string yu(string x,string y)
{
	string ss, init;
	if(x.size() < y.size()) swap(x,y);
	for(int i = 1; i <= x.size() - y.size(); i++) init += '0';
	y = init + y;
	for(int i = 0; i < x.size(); i++) {
		if(x[i] == '1' && y[i] == '1') ss += '1';
		else ss += '0';
	}
	return ss;
}
int qiuhe(string ss)
{	
	int sum = 0;
	int p = 1;
	for(int i = ss.size() - 1; i >= 0; i--) {
		sum += p * (ss[i]-'0');
		p *= 2;
	}
	return sum;
}
void f(int pos)
{
	if(pos > n) {
		int dex = 0;
		for(int i = 1; i <= n; i++) {
			if(b[i] == 1) dex++;
		}
		if(dex != m) return;
		string an;
		for(int i = 1; i <= n; i++) {
			if(b[i] == 1) {
				an = s[i];
				break;
			}
		}
		for(int i = 1; i <= n; i++) {
			if(b[i] == 1) {
				an = yu(an,s[i]);
			}
		}
		ans = max(ans,qiuhe(an));
		return;
	}
	b[pos] = 1;
	f(pos+1);
	b[pos] = 0;
	f(pos+1);
}
bool cmp(int a,int b)
{
	return a > b;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		s[i] = change(a[i]);
	}
	if(n == m) {
		string w;
		w = s[1];
		for(int i = 1; i <= n; i++) {
			w = yu(w,s[i]);
		}
		ans = qiuhe(w);
		cout << ans;
		return 0;
	} else if(n > 2000) {
		sort(a+1,a+n+1,cmp);
		string w;
		w = s[1];
		for(int i = 1; i <= m; i++) {
			w = yu(w,s[i]);
		}
		ans = qiuhe(w);
		cout << ans;
		return 0;
	}
	f(1);
	cout << ans;
	return 0;
}

