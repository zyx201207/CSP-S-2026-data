#include <bits/stdc++.h>
using namespace std;
int n,m,s[100001],q[100001][2],p[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i ++) {
		cin >> s[i];
	}
	for (int i = 0;i < n;i ++) {
		memset(q,0,sizeof(q));
		int k = i;
		for (;k < n;k ++) {
			if (q[s[k]][0]) {
				for (int j = q[s[k]][1];j <= k;j ++) {
					q[j][0] = 0;
				}
			}
			q[s[k]][0] ++;
			q[s[k]][1] = k;
		}
		for (int t = i;t < k - 1;t ++) {
			p[t] = q[s[k]][0];
		}
	}
	for (int i = 1;i <= m;i ++) {
		cout << p[i] << " ";
	}
	return 0;
}
