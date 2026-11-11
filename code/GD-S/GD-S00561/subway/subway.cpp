#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1010],k[1010],a[1010][1010],t[1010][1010],x[2010],y[2010];
void dfs(int x,int y,int u){
	if(x == y)cout << u << endl;
	for(int i = 1;i <= k[x];i++){
		dfs(a[x][i],y,u+t[x][i]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> x[i] >> y[i];
		dfs(x[i],y[i],w[x[i]]);
	}
	return 0;
} 
