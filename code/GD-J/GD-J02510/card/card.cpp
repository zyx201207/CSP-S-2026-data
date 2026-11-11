#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int a[maxn];
int cnt[maxn], lst[maxn], pai[maxn];
bool have[maxn];
int now, n, m;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		memset(lst, 0, sizeof(lst));
		memset(pai, 0, sizeof(pai));
		memset(have, 0, sizeof(have));
		int now = 1;
		for(int j = i; j <= n; j++){
			int will = a[j], last = lst[a[j]];
			if(last != 0){
				for(int k = last; k <= now - 1; k++){
					lst[pai[k]] = 0;
					pai[k] = 0;
				}
				now = last;
			}
			lst[will] = now;
			pai[now] = will;
//			for(int k = 1; k <= now; k++){
//				cout << pai[k] << ' ';
//			}
//			cout << '\n';
			now++;
		}
		for(int j = 1; j <= now - 1; j++){
//			cout << pai[j] << ' ';
			have[pai[j]] = true;
		}
//		cout << '\n';
		for(int j = 1; j <= m; j++){
//			cout << have[j] << ' ';
			if(have[j]) cnt[j]++;
		}
//		cout << '\n';
	}
	for(int i = 1; i <= m; i++){
		cout << cnt[i] << ' ';
	}
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

