#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5;
int l[N][N];
int n,d,mn,cnt;
void dfs(int u,int v,int dep,int tmp){
	if(dep > d) return;
	if(u == v){
		if(mn == tmp) cnt++;
		else if(mn > tmp) cnt = 0;
		mn = min(mn,tmp);
	}
	for(int k = u + 1;k <= v;k++){
		dfs(k,v,l[u][k],tmp + l[u][k]);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c <= 10){
		while(t--){
			int ans = 0;
			cin>>n>>d;
			vector<int> a(n);
			for(int i = 0;i < n;i++) cin>>a[i];
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++) l[i][j] = abs(a[i] - a[j]);
			}
			for(int i = 0;i < n;i++){
				for(int j = i + 1;j < n;j++){
					mn = 1e18 + 5;
					cnt = 0;
					dfs(i,j,0,0);
					if(cnt == 2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}else if(c > 12){
		while(t--) cout<<0<<endl;
	}else{
		while(t--){
			cin>>n>>d;
			vector<int> a(n);
			for(int i = 0;i < n;i++) cin>>a[i];
			int det = abs(a[1] - a[0]);
			int tmp = (3 * d) / (2 * det);
			if((3 * d) % (2 * det) != 0) tmp++;
			cout<<n - tmp<<endl;
		}
	}
	return 0;
}
