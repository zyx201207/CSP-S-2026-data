#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=2e6;

//duo ce yao qing kong
//kai ll

int c,T;

ll n,d;
ll a[MAXN+5],mv[MAXN+5];
ll g[305][305],cnt[305][305];

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--) {
    	memset(a,0,sizeof(a));
    	memset(mv,0,sizeof(mv));
    	scanf("%lld%lld",&n,&d);
    	for(int i=1;i<=n;i++) {
    		scanf("%lld",&a[i]);
		}
		memset(g,0x3f,sizeof(g));
		memset(cnt,0,sizeof(cnt));
		a[n+1]=(1ll<<60);
		int pos=1;
		for(int i=1;i<=n;i++) {
			g[i][i]=0;
			while(pos<=n&&a[pos]-a[i]<=d) {
				pos++;
			}
			mv[i]=pos-1;
			for(int k=i+1;k<=mv[i];k++) {
				g[i][k]=1;
				cnt[i][k]=1;
			}
		}
		for(int k=1;k<=n;k++) {
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					if(g[i][k]+g[k][j]<g[i][j]) {
						g[i][j]=g[i][k]+g[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(g[i][k]+g[k][j]==g[i][j]) {
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				ans+=(cnt[i][j]==2);
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
