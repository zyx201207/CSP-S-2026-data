#include<bits/stdc++.h> 
using namespace std;
const int maxn = 3 * 1e5 + 5;
int n, m, arr[maxn], number[maxn], cnt[maxn], card[maxn];
bool f(int num) {
	for(int i =0; i < n; i++) {
		if(card[i] == num) return 1;
	}
	return 0;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int l = 0;
	for(int i = 0; i < n; i++) {
		l = i;
		for(int k = l; k < n; k++) {
			if(f(arr[k])) {
				for(int k1 = 0; k1 < k; k1++) {
						card[k1] = 0;
				}
			}
			card[k] = arr[k];	
		}
		int num = 0;
		for(int j = 0; j < n; j ++) {
			if(card[j] == 0) continue;
			for(int k = 1; k <= m; k++) {
				if(card[j] == k){
					number[card[j] - 1] = 1;
				}
			}
		}
		for(int j = 0; j < n; j ++) {
			if(number[j] == 1) cnt[j] ++;
			card[j] = 0;
			number[j] = 0;
		}
	}
	for(int i = 0; i < m; i++) cout << cnt[i] <<" ";
	return 0;
}
