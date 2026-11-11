#include <bits/stdc++.h>
using namespace std;

const int N = 500000;
int a[N+10], b[N+10][2], cnt[N+10], sum[N+10][2], ans[N+10];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, ren = 1;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] != a[i-1]){
			b[ren++][0] = a[i];
		}bc[ren][1]++;	
	}for(int i = 1;i <= ren;i++){
		int N = b[i][0];
		for(int j = i;j <= ren;j++){
			if(b[j][0] == N){
				N = j;
			}
		}for(int j = N;j <= ren;j++){
			cnt[j] = b[j][0];
			if (sum[j][0] == 1){
				
			}else{
				sum[j][0]++;
				sum[j][1] = j;
			}
		}for(int j = 1;j <= m;j++){
			if(sum[m][0]){
				ans[m] += b[i][1];
			}
		}
	}for(int i = 1;i <= n;i++){
		cout << ans[i];
	}return 0;
}
