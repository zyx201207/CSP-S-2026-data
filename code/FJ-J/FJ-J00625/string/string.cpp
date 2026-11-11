#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
int n;
bool A = true;
string str;
struct node {
	int a;
	string c;
} w[N];
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;        
	for(int i = 1; i <= n; i ++)  {
		int a;
		string ch;
		cin >> a >> ch;
		if(a > 2e5) {
			w[i].a = a;
			w[i].c = ch;
		}
		else
			while(a --) {
				str += ch;
			}
		if(i != 1)
			if(w[i].a != w[i - 1].a || (w[i].a == 0 || w[i - 1].a == 0)) {
				A = false;
			}
	}
	if(A) {
		for(int i = 1; i <= n / 2; i ++) {
			if(w[i].c != w[n - i + 1].c)
				ans += w[i].a;
		}
		cout << ans;
		return 0;
	}
	for(int i = 0; i <= str.size() / 2; i ++) {
		if(str[i] != str[str.size() - i - 1])
			ans ++;
	}
	cout << ans;
	return 0;
}
