#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
char c[200005];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	int now = n;
	long long ans = 0;
	for(int i = 1;i <= n;i++) {
		int dist = a[i];
		while(dist > 0) {
			if(c[i] != c[now]) {
				int x = dist,y = a[now],z = a[i];
				ans += min(x,min(y,z));
				dist -= min(x,min(y,z));
				a[now] -= min(x,min(y,z));
				if(a[now] == 0) now--;
			}
			else {
				int x = dist,y = a[now],z = a[i];
				dist -= min(x,min(y,z));
				a[now] -= min(x,min(y,z));
				if(a[now] == 0) now--;
			}
		}
		a[i] = 0;
	}
	printf("%lld",ans);
	return 0;
} 
