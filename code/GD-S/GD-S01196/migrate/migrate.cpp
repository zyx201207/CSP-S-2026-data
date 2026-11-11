#include<bits/stdc++.h>
using namespace std;
namespace my_space {
	using ll = long long;
	using exl = __int128;
	int constexpr N = 305;
	ll a[N];
	int dis[N][N];
	int main() {
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int c,t;
		cin>>c>>t;
		while(t--) {
			int n;
			ll d;
			cin>>n>>d;
			memset(dis,0x3f,sizeof dis);
			for(int i = 1; i<=n; i++) {
				cin>>a[i];
			}
			a[0] = -3e18,a[n+1] = 3e18;
			for(int i = 1; i<=n; i++) {
				int l = i-1;
				while(a[i]-a[l]<=d) {
					dis[i][l] = 1;
					dis[l][i] = 1;
					l--;
				}
				int r = i+1;
				while(a[r]-a[i]<=d) {
					dis[i][r] = 1;
					dis[r][i] = 1;
					r++;
				}
			}
			for(int i =1; i<=n; i++) dis[i][i] = 0;
			for(int k = 1; k<=n; k++) {
				for(int i = 1; i<=n; i++) {
					for(int j = 1; j<=n; j++) {
						dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
			int ans=0;
			for(int i = 1; i<=n; i++) {
				for(int j = i; j<=n; j++) {
					int temp = dis[i][j];
					int sum=0;
					for(int k=1; k<=n; k++) {
						if(dis[i][k]+dis[j][k] == temp) sum++;
					}
					if(sum==temp+2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}
int main() {
	return my_space::main();
}

