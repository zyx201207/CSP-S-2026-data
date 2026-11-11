#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+10;
int ans[ms],v[ms];
int ans_ = -1;
int n,m;
int a[ms];

void f(int cnt) {
	if(cnt == m) {
		int sum = a[ans[0]];
		for(int i = 1;i < m;i++) {
			sum &= a[ans[i]];
		}
		ans_ = max(ans_,sum);
		return;
	}
	
	for(int i = 1;i <= n;i++) {
		if(v[i]) continue;

		v[i] = 1;
		ans[cnt] = i;
		f(cnt+1);
		v[i] = 0;	
	}
}

int main() {
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}

	f(0);

	cout << ans_;
}
