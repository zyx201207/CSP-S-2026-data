#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e3+5,inf=1e18;
int C,T,n,m,ans;
int a[N],b[N],dis[N][N],tot[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]>m){
					b[i]=j-1;
					break;
				}
			}
			if(!b[i]) b[i]=n;
		}
		for(int i=1;i<=n;i++){
			int x=i,cnt=0;
			for(int j=i+1;j<=n;j++){
				if(j>x) x=b[x],cnt++;
				if(j>x) break;
				dis[i][j]=cnt;
			}
			dis[i][i]=inf;
		}
		for(int i=1;i<=n;i++){
			queue<pii> q;
			q.push({i,0});
			while(q.size()){
				pii u=q.front();q.pop();
				if(u.se==dis[i][u.fi]) tot[i][u.fi]++;
				for(int j=u.fi+1;j<=n;j++){
					if(a[j]-a[u.fi]>m) break;
					q.push({j,u.se+1});
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(tot[i][j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++){
			b[i]=0;
			for(int j=i;j<=n;j++) dis[i][j]=0,tot[i][j]=0;
		}
		ans=0;
	}
	return 0;
}
