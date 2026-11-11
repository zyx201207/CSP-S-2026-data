#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 100;
const int INF = 1e9;

int n,ans;
int f[N][N],d[N][N];

ll dd;
ll a[N],aa[200100],yy[200100];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		if(n <= N){
			cin>>n>>dd;ans = 0;
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) d[i][j] = INF;
		for(int i = 1;i <= n;i++) d[i][i] = 0;
		
		int r = n;
		for(int u = n-1;u >= 1;u--){
			while(a[r] - a[u] > dd) r--;
			if(r == u) continue;
			for(int v = u+1;v <= n;v++){
				if(v <= r){
					d[u][v] = 1;
					f[u][v] = 1;
					continue;
				}
				if(d[r][v] > n) break;
				int sum = 0,rr = r;
				while(rr > u && sum <= 2 && d[rr][v] == d[r][v]) sum += f[rr][v],rr--;
				if(sum == 2) ans++;
				d[u][v] = d[r][v] + 1;
				f[u][v] = sum;
			}
		}
		
		cout<<ans<<'\n';
		continue;
		}
		
		cin>>n>>dd;
		for(int i = 1;i <= n;i++) cin>>aa[i];
		int fl;
		for(fl = 1;fl <= n;fl++){
			if(aa[n] - aa[fl] <= dd) break;
		}
		n--;
		for(int i = fl;i <= n;i++) aa[i] = aa[i+1],yy[i] = n;
		int r = n;
		ll ans = 0;
		for(int i = fl-1;i >= 1;i--){
			while(aa[r] - aa[i] > dd) r--;
			yy[i] = r;
			ans += r - yy[r-1];
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
