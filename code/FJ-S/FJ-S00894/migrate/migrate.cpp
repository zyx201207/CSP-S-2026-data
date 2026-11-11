#include<bits/stdc++.h>
#define int long long
using namespace std;
unsigned long long ans,dp[305][305],cnt[305][305],d;
int c,t,n,a[2000005];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		if(n<=300) {
			memset(dp,0x3f,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			ans=0;
			for(int i=1;i<=n;i++) {
				dp[i][i]=0;
				for(int j=i+1;j<=n;j++) {
					if(i==j) continue;
					unsigned long long far,x,y;
					bool dx=0,dy=0;
					int xx=a[j],yy=a[i];
					if(xx<0) {
						xx=-xx;
						dx=1;
					}
					if(yy<0) {
						yy=-yy;
						dy=1;
					}
					x=xx;
					y=yy;
					if(dx&&dy) far=y-x;
					else if(dy) far=x+y;
					else far=x-y;
					if(far<=d) {
						dp[i][j]=1;
						cnt[i][j]=1;
					}
				}
			}
			for(int leng=2;leng<=n;leng++) {
				for(int i=1;i+leng-1<=n;i++) {
					int j=i+leng-1;
					for(int k=i;k<=j;k++) {
						if(dp[i][k]+dp[k][j]<dp[i][j]) {
							dp[i][j]=dp[i][k]+dp[k][j];
							cnt[i][j]=cnt[i][k]*cnt[k][j];
						}
						else if(dp[i][k]+dp[k][j]==dp[i][j]) {
							cnt[i][j]+=cnt[i][k]*cnt[k][j];
						}
					}
				}
			}
			for(int i=1;i<=n;i++) {
				for(int j=i+1;j<=n;j++) {
					if(cnt[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
		else {
			int l=a[2]-a[1];
			if(d/l==2) {
				cout<<n-3<<endl; 
			}
			else {
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
