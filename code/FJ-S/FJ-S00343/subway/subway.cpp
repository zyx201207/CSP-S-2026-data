#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6.3e4+10;
int c,n,m,d,q,w[N],k[N],a[505][N],t[505][N],ans=1e9+10;
bool f[505][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int a1=0,t1=0;
			cin >> a1 >> t1;
			a[i][a1]=t1;
			f[i][a1]=1;
		}
	}
	for(int i=1;i<=q;i++){
		int x=0,y=0;
		cin >> x >> y;
		for(int j=1;j<=n;j++){
			if(f[j][x]==1 && f[j][y]==1){
				ans=min(ans,(w[x]+w[y]+a[j][x]+a[j][y]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
