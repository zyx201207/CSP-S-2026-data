#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int n, d, a[N], nxt[N], preL[N], preR[N];
int ans, dis[N], num[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int c, T; cin >> c >> T;
	while(T--){
		ans = 0;
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		if(a[n]-a[1]<=d){
			cout << (n-2) << '\n'; continue;
		}
		int l = 1, r = 1;
		while(l <= n){
			while(r<n&&a[r+1]-a[l] <= d) r++;
			nxt[l] = r; l++;
		}
		for(int i=1;i<=n;i++){
			for(int j=i-1;j;j--) dis[j] = n+1, num[j]=0;
			dis[i] = 0; num[i]=1;
			for(int j=i-1;j;j--){
				int p = min(i,nxt[j]);
				if(j==nxt[j]) break;
				dis[j] = dis[p]+1;
				int x = p;
				while(dis[x]==dis[p]){
					num[j]+=num[x]; x--;
					if(num[j]>2) break;
				}
				if(num[j]==2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
1
5 2
1 2 3 4 5
*/
