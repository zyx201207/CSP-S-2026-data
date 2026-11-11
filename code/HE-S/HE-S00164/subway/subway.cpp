#include<bits/stdc++.h>
using namespace std;

const int N = 1005,inf = 0x3f3f3f3f;

int c,n,m,d,q;
int e[N][N],w[N],ans;
int l,r;
bool vis[N];
void dfs(int x,int val,bool flag){
	if(x == r && flag == 0){
		ans = min(ans,val);
		return ; 
	}
	if(x == r && flag){
		dfs(x,val + w[x],0);
	}
	if(!flag){
		dfs(x,val + w[x],1);
	}else{
		for(int i = 1;i <= m;i ++ ){
			if(e[x][i] != inf && !vis[i]){
				vis[x] = vis[i] = true;
				dfs(i,val + e[x][i],1);
				vis[x] = vis[i] = false;
			}
		}
	}
	return ;
}

void solve(){
	
	cin >> l >> r;
	ans = inf;
	memset(vis,0,sizeof vis);
	dfs(l,0,0);
	cout << ans << '\n';
}

int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= N;i ++ )for(int j = 1;j <= N;j ++ ) e[i][j] = inf;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++ ){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++ ){
		int k;
		cin >> k;
		vector<int> x(k + 10),y(k + 10);
		for(int j = 1;j <= k;j ++ ){
			cin >> x[j] >> y[j];
		}
		for(int j = 1;j <= k;j ++ ){
			for(int jj = 1;jj <= k;jj ++ ){
				if(j != jj){
					e[x[j]][x[jj]] = y[j] + y[jj];
//					cout << e[j][jj] <<" "<<j << " " << jj<<'\n';
					e[x[jj]][x[j]] = y[j] + y[jj];
				}
			}
		}
	}
	while(q -- ){
		solve();
	}
	return 0;
} 
