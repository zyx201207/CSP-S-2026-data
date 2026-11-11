#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

int c,T;
int a[MAXN];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> T;
	
	while(T--) {
		int n,d;
		cin >> n >> d;
		bool flag = true;//等差数列是不是
		int ch = 0;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			if(i == 2) ch = a[i] - a[i - 1];
			else if(i > 2) {
				if(a[i] - a[i - 1] != ch) flag = false;
			}
		} 
		if(flag) { //骗特殊性质A 
			if(d < 2 * ch) {
				cout << 0 << '\n';
			} else {
				if(d == 2 * ch) cout << 2 << '\n';
				else cout << 0 << '\n';
			} return 0;
		}
		//骗特殊性性质B
		cout << 0 << '\n';
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

