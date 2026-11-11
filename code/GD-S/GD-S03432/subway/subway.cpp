#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m,k,s,t,c,d,q,w[500005];

int f[3000][3000];//fijk 从i到j经过k为中转 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >>d >> q;
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i =1;i<=m;i++)cin >> w[i];
	int tot = 0;
	for(int i =1;i<=n;i++){
		cin >> k;
		for(int j = 1;j<=k;j++){
			int id,t;
			cin >>id >> t;
			f[id][100+i] = t;//到同站异线路的点 (站台到站厅 
			f[100+i][id] = t;
			f[0][id] = t;
			f[id][0] = t;
			f[id][200+i] = 0;//异站同线路 
			f[200+i][id] = 0; 
		}
	}
	for(int k =1;k<=m+300;k++){
		for(int i =1;i<=m+300;i++){
			for(int j =1;j<=m+300;j++){
				f[i][j] = min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	
	
	int u,v,ans;
	while(q--){
		cin >> u >> v;
		ans = 0;
		ans +=w[u]+w[v];int res = 0x3f3f3f3f;
		res= min(res,f[u][v]);
		res+=f[0][u]+f[v][0];
		if(res == 0x3f3f3f3f)res = 0;
		cout << ans+res<<"\n";
	}
	return 0;
}
