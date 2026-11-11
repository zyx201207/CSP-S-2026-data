#include<iostream>

using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
int n, a1[N], a2[N], m;
ll s[N], len, ans;
char c1[N], c2[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a1[i] >> c1[i];
		len += a1[i];
	}
	len /= 2;
	while(n){
		if(len >= a1[n]){
			a2[++m] = a1[n];
			c2[m] = c1[n];
			len -= a1[n];
			a1[n--] = 0;
		}
		else if(len){
			a2[++m] = len;
			c2[m] = c1[n];
			a1[n] -= len;
			len = 0;
		}
		else break;
	}
	if(s[n]&1) a1[n]--;
	for(int i = 1, j = 1; i <= n && j <= m;){
		int mn = min(a1[i], a2[j]);
		if(c1[i] != c2[j]) ans += mn;
		a1[i] -= mn;
		a2[j] -= mn;
		while(a1[i] == 0 && i <= n) i++;
		while(a2[j] == 0 && j <= m) j++;
	}
	cout << ans;
	return 0;
}
