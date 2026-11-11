#include <bits/stdc++.h>
using namespace std;
const long long Ma=1e18-1;
int c,n,m,d,q;
long long w[500005],f[355][355],ans=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	if(1<=c&&c<=6){
		int a,k;
		long long t;
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				f[i][j]=Ma;
			}
		}
		for(int i=1;i<=n+m;i++){
			f[i][i]=0;
		}
		int m2=m;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			m2++;
			for(int j=1;j<=k;j++){
				scanf("%d%lld",&a,&t);
				f[a][m2]=t;
				f[m2][a]=t;
			}
		}
		for(int k=1;k<=n+m;k++){
			for(int i=1;i<=n+m;i++){
				for(int j=1;j<=n+m;j++){
					if(i==j){
						continue;
					}
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		int x,y;
		for(int i=1;i<=q;i++){
			scanf("%d%d",&x,&y);
			ans=w[x]+w[y]+f[x][y];
			printf("%lld\n",ans);
		}
	}
	
	
	
	return 0;
}
