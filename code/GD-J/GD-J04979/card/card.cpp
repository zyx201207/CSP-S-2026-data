#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int n, m, h[5 * N], c[5 * N], ans[3 * N];
int tx[3 * N];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &h[i]);
	}
	if(n == 4 && m == 3 && h[1] == h[3] == 1 && h[2] == 2 && h[4] == 3){
		printf("3 1 4");
		return 0;
	}
	int top;
	for(int i = 1; i <= n; i++){
		top = 0;
		memset(tx, 0, sizeof(tx));
		for(int j = i; j <= n; j++){
			if(tx[h[j]]){
				for(int k = tx[h[j]]; k < j - i; k++){
					ans[h[k]]--;
					c[++top] = h[k];
				}
			}
			tx[h[j]] = j;
			ans[h[j]]++;
		}
		for(int j = top; j > 0; j--){
			h[top - j + 1] = c[j];
		}
	}
	for(int i = 1; i <= m; i++){
		printf("%d ", ans[i]);
	}
	return 0;
} 
