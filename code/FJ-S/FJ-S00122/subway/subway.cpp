#include <bits/stdc++.h>
using namespace std;
int rd(){
	char ch = getchar();
	int ret = 0;
	while(!('0' <= ch && ch <= '9')) ch = getchar();
	while('0' <= ch && ch <= '9') ret = (ret << 3) + (ret << 1) + ch - '0', ch = getchar();
	return ret;
}

int c, n, m, d, q;
int w[500002];

vector<int> vecx[502], valx[502], vecz[500002], valz[500002];
long long disx[502][502];

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
	for(int i=1;i<=m;i++) w[i] = rd();
	
	for(int i=1;i<=n;i++) {
		int k;
		k = rd();
		for(int j=1;j<=k;j++){
			int x, y;
			x = rd(), y = rd();
			vecx[i].push_back(x);
			valx[i].push_back(y);
			vecz[x].push_back(i);
			valz[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) {
			disx[i][j] = 1e18;
		}
	}
	for(int i=1;i<=n;i++) disx[i][i] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<vecx[i].size();j++){
			int v = vecx[i][j], w = valx[i][j];
			for(int k=0;k<vecz[v].size();k++){
				int nxt = vecz[v][k], ww = valz[v][k];
				disx[i][nxt] = min(disx[i][nxt], 1ll * w + ww);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				disx[i][j] = min(disx[i][j], disx[i][k] + disx[k][j]);
			}
		}
	}
	
	while(q--){
		int x, y;
		x = rd(), y = rd();
		long long Ans = 1e18;
		for(int i=0;i<vecz[x].size();i++){
			for(int j=0;j<vecz[y].size();j++){
				Ans = min(Ans, 1ll*valz[x][i]+valz[y][j]+disx[vecz[x][i]][vecz[y][j]]);
			}
		}
		Ans = Ans + w[x] + w[y];
		printf("%lld\n",Ans);
	}
	
	return 0;
}
