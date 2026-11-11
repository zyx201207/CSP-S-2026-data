#include <bits/stdc++.h>
using namespace std;
queue <int> q;
int k[500005];
int t[300005];
int c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> k[i];
		
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			t[k[j]]++;
			q.push(k[j]);
			if (t[k[j]] == 1) {
				t[k[j]] = 0;
				q.pop();
				while (q.front() != k[j]) {
					q.pop();
				}	
			}
			if (j == n) {
				while (!q.empty()) {
					int l = q.front();
					c[l]++;
					q.pop();
				}	
			}
		}	
	}
	
	for (int i = 1;i <= n;i++) {
		if (c[i] != 0) cout << c[i];
	}
	return 0;
}
