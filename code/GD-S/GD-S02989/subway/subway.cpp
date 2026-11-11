#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=505, maxm=2e4+5;
int c, n, m, d, q;
int w[maxm], k[maxn], a[maxn][maxm], t1[maxn][maxm];
int t[maxn+maxm][maxn+maxm];
void solve1(){
	for(int k=1; k<=m+n; k++){
		for(int i=1; i<=m+n; i++){
			for(int j=1; j<=m+n; j++){
				if(t[i][k]<=0x3f3f3f3f&&t[k][j]<=0x3f3f3f3f){
					t[i][j]=min(t[i][j], t[i][k]+t[k][j]);
				}
			}
		}
	}
}
int solve2(int x, int y){
	return w[x]+w[y]+t[x][y];
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++){
		cin >> w[i];
	} 
	memset(t, 0x3f3f3f3f, sizeof(t));
	for(int i=1; i<=n; i++){
		cin >> k[i];
		for(int j=1; j<=k[i]; j++){
			cin >> a[i][j] >> t1[i][j]; 
			t[a[i][j]][m+i]=t[m+i][a[i][j]]=t1[i][j]; 
		}
	}
	solve1();
	for(int i=1; i<=q; i++){
		int x, y;
		cin >> x >> y;
		cout << solve2(x, y) << endl;
	}
	
	return 0;
}
