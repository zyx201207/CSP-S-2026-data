#include<bits/stdc++.h>
using namespace std;
const int N = 500010, M = 300010;
int n, m, arr[N], ans[M], num[N], vis[N], ind[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> arr[i];
	for(int i = 1;i <= n;i++) {
		int pos = 0;
		memset(vis, 0, sizeof(vis));
		memset(num, 0, sizeof(num));
		memset(ind, 0, sizeof(ind));
		for(int j = i;j <= n;j++) {
			if(vis[arr[j]] == 0) {
				num[++pos] = arr[j];
				ind[arr[j]] = pos;
				vis[arr[j]] = 1;
			}
			else {
				for(int x = ind[arr[j]] + 1;x <= pos;x++) vis[num[x]] = 0, num[x] = 0;
				pos = ind[arr[j]];
			}
		}
		for(int j = 1;j <= pos;j++) {
			ans[num[j]] ++;
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
	
	return 0;
} 
