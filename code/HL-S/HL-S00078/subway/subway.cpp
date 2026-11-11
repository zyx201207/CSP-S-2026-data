#include<bits/stdc++.h>
using namespace std;

const int N =1e3 + 5;
#define int long long
int c,n,m,d,q;
int w[N];
int ans = 1e18;
int a[505][N],t[505][N];
vector< pair<int,int> >e[N];
vector<int>p[N];
bitset<N>vis;
void dfs(int nw,int rd,int gl,int ct){
	if(ct > ans)return;
	if(nw == gl){
		ans = min(ans,ct);
		return;
	}
	for(int i = 1;i<= a[rd][0];i++){
		if(a[rd][i] != nw && !vis[a[rd][i]]){
			dfs(a[rd][i],rd,gl,ct);
		}
	}
	for(auto rr:p[nw]){
		if(rr != rd){
			dfs(nw,rr,gl,ct+1);
		}
	}
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	
	
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i][0];
		for(int j = 1;j <= a[i][0];j++){
			cin >> a[i][j] >> t[i][j];
			p[a[i][j]].push_back(i);
			
		}
	}
	
		for(int i = 1;i <= q;i++){
			int x, y;
			ans = 1e18;
			cin >> x >> y;	
			
			
				dfs(x,p[x][0],y,0);
				vis[x] = 0;
			
			cout << ans << "\n";
		}
	
	
	
	//return 0;
}
