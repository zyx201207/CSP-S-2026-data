#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

int c,t;
int n,d;
int ans,num,minn;
int a[N];

void solve(int x,int y,int dis){
	if (x == y){
		if (dis < minn){
			minn = dis;
			num = 1;
		}
		else if (dis == minn) num++;
		
		return;
	}
	int v = x + 1;
	while (a[v] - a[x] <= d && v<=y){
		solve(v,y,dis+1);
		v++;
	}
} 

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		ans = 0;
		for (int i=1;i<=n;++i) cin >> a[i];
		for (int i=1;i<=n;++i){
			for (int j=i+1;j<=n;++j){
				num = 0;
				minn = 2000000000000000000;
				solve(i,j,0);
				if (num == 2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	
	
	
	
	return 0;
}




