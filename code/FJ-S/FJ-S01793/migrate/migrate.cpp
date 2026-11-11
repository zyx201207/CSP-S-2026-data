#include <cstdio>
#include <cstring>
#define int long long
#define MOD 998244353
using namespace std;
int c,T,n,d,pos[5005],g[5005][5005],ct[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--&&scanf("%lld%lld",&n,&d)){
		memset(g,0x3f,sizeof(g));
		int ans=0;
		for(int i=1;i<=n;i++)scanf("%lld",pos+i),g[i][i]=0,ct[i][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(pos[j]-pos[i]<=d)g[i][j]=1,ct[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(g[i][k]==0x3f3f3f3f3f3f3f3f)continue;
				for(int j=1;j<=n;j++){
					if(g[i][j]>g[i][k]+g[k][j])g[i][j]=g[i][k]+g[k][j],ct[i][j]=(ct[i][k]*ct[k][j])%MOD;
					else if(g[i][j]==g[i][k]+g[k][j])ct[i][j]=(ct[i][j]+(ct[i][k]*ct[k][j])%MOD)%MOD;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)ans+=ct[i][j]==2;
		}
		printf("%lld\n",ans);
	}
}
