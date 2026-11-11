#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int sk[N], sh[M], p[N];
int bo[N]; 
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++){
		memset(sk, 0, sizeof(sk));
		memset(bo, false, sizeof(bo));
		int k = 0;
		for(int j = i - 1; j < n; j++){
			if(bo[p[j]] > 0){
				while(1){
					if(sk[k] == p[j])break;
					k--;
					bo[sk[k]]--;
				}
			}
			else {
				sk[k] = p[j];
			}
			bo[p[j]]++;
			k++;
		}
		for(int j = 0; j < k; j++){
			int y = sk[j];
			sh[y]++;
		}
	}
	for(int i = 1; i <= m; i++)cout << sh[i] << " ";
	return 0;
}
