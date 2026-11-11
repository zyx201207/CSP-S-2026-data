#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 5;
const int MAXM = 3e5 + 5;

int id[MAXM]; // 队列中最后一次出现位置 
int n, m, a[MAXN], vis[MAXM], cnt[MAXM], ans[MAXM];

void clear(){
	fill(vis + 1, vis + m + 1, 0);
	fill(cnt + 1, cnt + m + 1, 0);
	fill(id + 1, id + m + 1, 0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){ // 第i局 
		for(int j = i; j <= n; j++){
			cnt[a[j]]++;
			if(cnt[a[j]] > 1){
				for(int k = id[a[j]]; k < j; k++){
					if(vis[k] == -1){
						continue;
					}
					vis[k] = -1;
					cnt[a[k]]--;
				}
			}
			vis[j] = 1; // 队列中存在第j个
			id[a[j]] = j; // 更新最后出现位置 
		}
		for(int l = i; l <= n; l++){
			if(vis[l] == 1){
				ans[a[l]]++;
			} 
		} 
		clear();
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	} 
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
