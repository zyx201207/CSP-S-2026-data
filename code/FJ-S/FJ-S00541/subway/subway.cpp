#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505,MAXM = 5 * 1e5+5;
int c,n,m,d,q,w[MAXM],ans,k[MAXN],x,y;
int line[MAXN][MAXM];
void dfs(int noww,int l,int s){
	if(noww == y){
		s += line[l][y] + w[y];
		ans = min(ans,s);
	}
	for(int i = 0;i < m;i++){
		if(i == noww) continue;
		if(line[l][i] == 0) continue;
		for(int j = 0;j < n;j++){
			bool flag = 0;
			if(line[j][i] != 0 && j != l){
				flag = 1;
				s += line[j][i] + line[l][i];
			}
			dfs(i,j,s);
			if(flag) s-=line[j][i] + line[l][i];
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++) cin >> w[i];
	for(int i = 0;i < n;i++){
		cin >> k[i];
		for(int j = 0;j < k[i];j++){
			int st;
			cin >> st;
			cin >> line[i][st - 1];
		}
	}
	while(q--){
		cin >> x >> y;
		x-=1;
		y-=1;
		ans = 114514;
		for(int i = 0;i < n;i++){
			if(line[i][x] != 0) {
				dfs(x,i,w[x] + line[i][x]);
			}
		}
		cout << ans << endl;
	}
}
