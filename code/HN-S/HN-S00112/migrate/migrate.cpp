#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int t,n,m,dist[N][N],f[N][N],op[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&t,&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dist[i][j]=0x3f3f3f3f;
				f[i][j]=0;
			}
			scanf("%lld",&op[i]);
			dist[i][i]=0;
		}
		for(int i=1; i<=n; ++i){
			for(int j=i+1; j<=n; ++j){
				if(op[j]-op[i]>m)break;
				dist[i][j]=1;
				dist[j][i]=1;
				f[i][j]=1;
				f[j][i]=1;
			}
		}
		for(int k=1; k<=n; ++k){
			for(int i=1; i<=n; ++i){
				if(i==k)continue;
				for(int j=1; j<=n; ++j){
					if(i==j || j==k)continue;
					if(dist[i][k]+dist[k][j]<dist[i][j]){
						dist[i][j]=dist[i][k]+dist[k][j];
						f[i][j]=f[i][k]*f[k][j];
					}else if(dist[i][k]+dist[k][j]==dist[i][j])f[i][j]+=f[i][k]*f[k][j];
				}
			} 
		}
		int ans=0;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				if(f[i][j]==2)++ans;
			}
		} 
		printf("%lld\n",ans/2);
	}
	
	return 0;
} 

