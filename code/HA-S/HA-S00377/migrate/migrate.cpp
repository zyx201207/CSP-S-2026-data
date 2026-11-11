#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x;
	cin>>x;
	return x;
}
const int N=2000010,N1=310,INF=1000000000000000000;
int x[N],dis1[N1][N1],cnt1[N1][N1];
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read();
	for(int t=read();t>0;t--) {
		int n=read(),d=read();
		for(int i=1;i<=n;i++) {
			x[i]=read();
		}
		if(c<=6) {
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					dis1[i][j]=INF;
					cnt1[i][j]=0;
				}
			}
			for(int l=1,r=0;l<=n;l++) {
				while(r<n&&x[r+1]-x[l]<=d) {
					r++;
				}
				for(int i=l;i<=r;i++) {
					dis1[l][i]=1;
					cnt1[l][i]=1;
				}
			}
			for(int i=1;i<=n;i++) {
				dis1[i][i]=1;
				cnt1[i][i]=1;
			}
			for(int k=1;k<=n;k++) {
				for(int i=1;i<=n;i++) {
					for(int j=1;j<=n;j++) {
						if(dis1[i][j]>dis1[i][k]+dis1[k][j]) {
							dis1[i][j]=dis1[i][k]+dis1[k][j];
							cnt1[i][j]=cnt1[i][k]*cnt1[k][j];
						}
						else if(dis1[i][j]==dis1[i][k]+dis1[k][j]) {
							cnt1[i][j]+=cnt1[i][k]*cnt1[k][j];
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					if(cnt1[i][j]==2) {
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
