#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
bool flag[200005];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int ans = (1 << 30) - 1;
	int count = 0;
	for(int i = 1 << 30;i >= 1;i >>= 1) {
		int cnt = 0;
		for(int j = 1;j <= n;j++) {
			if((a[j] & i) && !flag[j]) cnt++;
		}
		if(cnt < m) continue;
		for(int j = 1;j <= n;j++) {
			if(!(a[j] & i)) flag[j] = true;
		}
	}
	for(int i = 1;i <= n && count < m;i++) if(!flag[i]) ans &= a[i],count++;
	printf("%d",ans);
	return 0;
}
