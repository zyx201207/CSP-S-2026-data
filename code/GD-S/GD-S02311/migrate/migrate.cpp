#include<bits/stdc++.h>
#define ll long long
#define N 305
using namespace std;
ll a[N];
ll f[N][N],cnt[N][N];
ll c,T,n,d;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c>=0&&c<=6) {
		while(T--) {
			cin>>n>>d;
			for(int i=1; i<=n; i++) cin>>a[i];
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					f[i][j]=2*1e18;
					cnt[i][j]=1;
				}
				f[i][i]=0;
				cnt[i][i]=1;
			}
			for(int len=2; len<=n; len++) {
				for(int l=1; l+len-1<=n; l++) {
					int r=l+len-1;
					for(int k=r-1; k>=l; k--) {
						if(a[r]-a[k]<=d) {
							ll val=f[l][k]+1;
							if(val==f[l][r]) {
								cnt[l][r]+=cnt[l][k];
							}
							else if(val<f[l][r]) {
								f[l][r]=val;
								cnt[l][r]=1;
							}
						}
					}
				}
			}
			int ans=0;
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					if(cnt[i][j]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	} else {
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			if(a[2]-a[1]>d){
				cout<<0<<'\n';
			}
			else{
				int x=d/(a[2]-a[1]);
				if(x==1) cout<<0<<'\n';
				else{
					cout<<max(0*1ll,n-x)<<'\n';
				}
			}
		}
		return 0;
	}
}
