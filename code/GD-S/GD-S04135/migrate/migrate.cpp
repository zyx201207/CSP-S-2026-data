#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n;
ll a[2000005],f[5005][5005],ma[5005][5005],g[5005][5005],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ll ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",a+i);
		memset(f,0x3f,sizeof f);
		memset(ma,0,sizeof ma);
		memset(g,0,sizeof g);
		for(int i=1;i<=n;i++) f[i][i]=0,g[i][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) f[i][j]=1,g[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(f[i][k]+f[k][j]==f[i][j]&&i!=k&&j!=k) g[i][j]+=g[i][k]*g[k][j];
					if(f[i][k]+f[k][j]<f[i][j]){
						f[i][j]=f[i][k]+f[k][j];
						if(i!=k&&j!=k) g[i][j]=g[i][k]*g[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(g[i][j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
