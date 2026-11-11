#include<bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for(int i = (a); i <= (b); i++)
#define ro(i, a, b) for(int i = (a); i >= (b); i--)
#define int long long 

const int N = 2e5 + 5;

int n;
int a;
char c;
char ch[100000005];
int pos;
int ans;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	fo(i, 1, n) {
		cin >> a >> c;
		while(a--) {
			ch[++pos] = c;
		}
	}
	ro(i, pos >> 1, 1) {
		if(ch[i] != ch[pos - i + 1]) ans++;
	}
	cout << ans;
	return 0;
}
/*

*/
