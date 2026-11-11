#include <bits/stdc++.h>
using namespace std;

const int ms = 5e3+10;
int n,m,a[ms];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	
	int ans[ms] = {0};
	
	int b[ms];
	int l = 1,r = 1;
	for(int i = 1;i <= n;i++) {
		for(int j = i;j <= n;j++) {
			for(int k = l;k <= r;k++) {
				if(b[k] == a[j]) {
					r = k-1;
					break;
				}
			}
			b[r+1] = a[j];
			r++;
		}
		for(int j = l;j <= r;j++) ans[b[j]]++;
	}
	
	for(int i = 1;i <= m;i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
