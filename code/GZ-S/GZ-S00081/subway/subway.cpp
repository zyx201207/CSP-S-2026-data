//GZ-S00081 六盘水市第二十四中学 周启明 
#include <bits/stdc++.h>
using namespace std;

int c;
long long n,m,d,q,x,y,ans;
bool fx,fy;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	long long w[m + 1],k[n + 1],at[n + 1][m + 1];
	bool f[n][m + 1];
	memset(f,0,sizeof(f));
	for (int i = 0;i < m;i++){
		cin >> w[i];
	}for (int i = 0;i < n;i++){
		cin >> k[i];
		for (int j = 0;j < k[i];j++){
			cin >> x >> y;
			at[i][x] = y;
			f[i][x] = 1;
		}
	}while (q--){
		ans = 0;
		fx = fy = 0;
		cin >> x >> y;
		ans += w[x - 1] + w[y - 1];
		for (int i = 0;i < n;i++){
			if (f[i][x] && !fx){
				ans += at[i][x];
				fx = 1;
			}if (f[i][y] && !fy){
				ans += at[i][y];
				fy = 1;
			}
		}cout << ans << "\n";
	}
	return 0;
}

