#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 5e5 + 15;
int c,n,m,d,q,at;
int w[N];
int a[500][N];
int t[500][N];
int ans[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++){
		cin >> a[i][0];
		for (int j = 1;j <= a[i][0];j++){
			int b,c;
			cin >> b >> c;
			a[i][j] = b;
			t[i][b] = c;
			if (12 <= c && c <= 19){
				at = c;
			}
		}
	}
	if (7 <= c && c <= 11){ 
		for (int i = 1;i <= n;i++){
			if(ans[a[i][1]][a[i][2]] == 0){
				ans[a[i][1]][a[i][2]] = ans[a[i][2]][a[i][1]] = t[i][a[i][1]] + t[i][a[i][2]];
			}else{
				ans[a[i][1]][a[i][2]] = ans[a[i][2]][a[i][1]] = min(ans[a[i][1]][a[i][2]],t[i][a[i][1]] + t[i][a[i][2]]);
			}
		}
	}else if (12 <= c && c <= 19){
		for (int i = 1;i <= n;i++){
			for(int j = 1;j <= a[i][0];j++){
				for(int k = 1;k <= a[i][0];k++){
					if (j == k){
						continue;
					}
					ans[a[i][j]][a[i][k]] = 2 * at;
				}
			}
		}
	}else{
		for (int i = 1;i <= n;i++){
			for(int j = 1;j <= a[i][0];j++){
				for(int k = 1;k <= a[i][0];k++){
					if (j == k){
						continue;
					}
					if (ans[a[i][j]][a[i][k]] == 0){
						ans[a[i][j]][a[i][k]] = t[i][a[i][j]] + t[i][a[i][k]];
					}else{
						ans[a[i][j]][a[i][k]] = min(ans[a[i][j]][a[i][k]],t[i][a[i][j]] + t[i][a[i][k]]);
					}
				}
			}
		}
	}
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= m;j++){
			for (int k = 1;k <= m;k++){
				if (i == j){
					break;
				}
				if (i == k || j == k || ans[i][j] == 0 || ans[j][k] == 0){
					continue;
				}
				if (ans[i][k] == 0){
					ans[i][k] = ans[i][j] + ans[j][k];
				}else{
					ans[i][k] = min(ans[i][k],ans[i][j] + ans[j][k]);
				}
			}
		}
	}
	for (int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
		cout << w[x] + ans[x][y] + w[y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
