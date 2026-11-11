#include <bits/stdc++.h>

int N, M, arr[500010], brr[500010], vis[500010];
int ans[300010], nxt[500010];

int main() {
	freopen("card.in", "r", stdin), freopen("card.out", "w", stdout);
//freopen("D:\\cspj\\down\\card\\card4.in", "r", stdin);
	std::cin >> N >> M;
	for (int i = 1; i <= N; i ++) std::cin >> arr[i];
	if (N <= 500) {
		for (int i = 1; i <= N; i ++) {
			for (int j = 1; j <= N; j ++) vis[j] = 0;
			for (int j = i; j <= N; j ++) {
				int kkk = 0;
				for (int k = j - 1; k >= i; k --) if (vis[k] && (arr[k] == arr[j])) {
					kkk = k;
					break;
				}
				
				if (kkk) {
					for (int k = kkk; k < j; k ++) vis[k] = 0;
				}
				vis[j] = 1;
			}
			
			for (int j = i; j <= N; j ++) vis[j] ? ans[arr[j]] ++ : 0;
		}
		
		for (int i = 1; i <= M; i ++) std::cout << ans[i] << " ";
	} else {
		for (int i = 1; i <= M; i ++) ans[arr[i]] ++;
		for (int i = 1; i <= M; i ++) std::cout << ans[i] << " ";
	}
	
	return 0;
}
