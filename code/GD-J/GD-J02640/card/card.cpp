#include<bits/stdc++.h>
using namespace std;
int n, r, ls[500005], cnt[500005], maxn;
bool used[500005];
int main(){
	freopen("card1.in", "r", stdin);
	cin >> n >> r;
	for (int i = 1;i <= n; ++ i){
		cin >> ls [ i ];
		maxn = max(maxn, ls [ i ]);
	}
	for (int round = 0;round <= r; ++ round){
		int st[500005], top = 0;
		memset(used, 0, sizeof used);
		cout << "[round " << round << "]\n";
		for (int i = round + 1;i <= n; ++ i){
			if (used [ ls [ i ] ] == 0){
				st [ top ++ ] = ls [ i ];
				used [ ls [ i ] ] = true;
			}else{
				while (st [ top - 1 ] != ls [ i ] && top > 0){
					top --;
					used [ top ] = false;
				}
				top ++;
			}
			for (int i = 0;i < 10; ++ i) cout << st [ i ] << " ";
			cout << "\n" << top << "\n";
		}
		for (int i = 0;i < top; ++ i) cnt [ st [ i ] ] ++;
	}
	for (int i = 1;i <= maxn;i ++) cout << cnt [ i ] << " ";
	return 0;
}
