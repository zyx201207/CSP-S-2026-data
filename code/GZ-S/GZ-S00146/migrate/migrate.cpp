//GZ-S00146 贵阳市第九中学 向一坤 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=309;
int c,T;
int n;ll d,a[N],f[N][N],g[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);while(T--){
		scanf("%d%lld",&n,&d);memset(f,0x3f,sizeof(f));memset(g,0,sizeof(g));
		ll ans=0;
		if(n>=300){printf("0\n");continue;}
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		for(int i=1;i<=n;++i){
			f[i][i]=0,g[i][i]=1;//printf("i=%d\n",i);
			for(int j=i+1;j<=n;++j){
				for(int k=j-1;k>=1;--k){
					if(a[j]-a[k]>d) break;
					f[i][j]=min(f[i][j],f[i][k]+1);
				}
				for(int k=j-1;k>=1;--k){
					if(a[j]-a[k]>d) break;
					if(f[i][j]-1==f[i][k])g[i][j]+=g[i][k];
				}
				if(g[i][j]==2) ++ans;
				//printf("%d,%d=%d\n",i,j,f[i][j]);
			}
		}printf("%lld\n",ans);
	}
	return 0;
}
/*
24pts 16:22
*/ 
