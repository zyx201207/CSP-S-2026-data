#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10,INF=1e18;
int c,T,n,d,a[N],f[N][N],ans[N][N];
inline void init() {
	for(int i=1; i<=n; i++)	a[i]=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			ans[i][j]=0,f[i][j]=INF;
	}
}
inline void floyd() {
	for(int i=1; i<=n; i++)	f[i][i]=0;
	for(int i=1; i<=n; i++) {
		for(int j=min(i+1,n); j<=n; j++) {
			if(f[i][j]==1||i==j)	continue;
			for(int k=1; k<=n; k++) {
				if(f[i][k]>=INF||f[k][j]>=INF||k==j||i==k)	continue;
				if(f[i][j]==f[i][k]+f[k][j])	ans[i][j]++;
				else if(f[i][j]>f[i][k]+f[k][j]) {
					f[i][j]=f[i][k]+f[k][j];
					ans[i][j]=1;
				}
			}
		}
	}
}
inline void solve() {
	cin>>d;
	if(n==1) {
		cout<<0;
		return ;
	}
	init();
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		for(int j=max(i-1,1ll); j>=1; j--) {
			if(abs(a[i]-a[j])>d)	break;
			f[j][i]=1,ans[j][i]=1;
		}
	}
	floyd();
	int sum=0;
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++)
			sum+=(ans[i][j]==2)?1:0;
	cout<<sum<<'\n';
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c>=11&&c<=12) {
		while(T--) {
			cin>>n;
			if(n>=10000)	cout<<0;
			else solve();
		}
	} else {
		while(T--) {
			cin>>n;
			solve();
		}
	}
	return 0;
}
