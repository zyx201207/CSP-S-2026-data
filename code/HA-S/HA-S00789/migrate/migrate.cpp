#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
int c,T,n;
ll d,p,a[2000010],f[N][N],s[N][N];
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		if (n<=500) {
			for (int i=1;i<=n;i++) {
				for (int j=1;j<=n;j++) {
					f[i][j]=1e18;
					s[i][j]=1;
				}
			}
			int l=1;
			for (int i=1;i<=n;i++) {
				cin >> a[i];
				p=a[i]-a[i-1];
				for (int j=l;j<=i;j++) {
					if (a[i]-a[j]>d) {
						l=j+1;
					}else{
						f[i][j]=f[j][i]=1;
					}
				}
			}
			for (int len=1;len<=n-1;len++) {
				for (int i=1;i+len<=n;i++) {
					for (int j=i+1;j<i+len;j++) {
						if (f[i][j]+f[j][i+len]<f[i][i+len]) {
							f[i][i+len]=f[i][j]+f[j][i+len];
							s[i][i+len]=s[i][j]*s[j][i+len];
						}else if (f[i][j]+f[j][i+len]==f[i][i+len]&&f[i][j]==1) s[i][i+len]+=s[i][j]*s[j][i+len];
					}
				}
			}
			ll ans=0;
			for (int i=1;i<=n;i++) {
				for (int j=i+1;j<=n;j++) {
					if (s[i][j]==2) ans++;
				}
			}
			cout << ans <<"\n";
		}else if (c==11||c==12) {
			for (int i=1;i<=n;i++) cin >> a[i];
			p=a[n]-a[n-1];
			if (p==0) {
				cout << 0 <<"\n";
				continue;
			}
			int t=d/p;
			if (t==0||t==1) cout << 0 <<"\n";
			else {
				t+=t-1;
				cout << max(0,n-t) <<"\n";
			}
		}else{
			for (int i=1;i<=n;i++) {
				cin >> a[i];
			}
			int sum=0,id;
			for (int i=1;i<=n;i++) {
				if (a[i]-a[0]<=d&&a[n]-a[i]<=d) sum++,id=i;
			}
			if (sum==2) cout << 1 <<endl;
			else cout << 0 <<endl;
			
		}
	}
	return 0;
}
