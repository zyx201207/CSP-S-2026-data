#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#define MIN(a,b) ((a)<(b)?(a):(b))
const int N=500+100,M=5e5+100;
int c,n,m,d,q;
int w[M];
int k[N];
std::vector<int> a[N],t[N],ra[M],rt[M];
long long b[N][N];
bool build[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",w+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",k+i);
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
			ra[a[i][j]].push_back(i);
			rt[a[i][j]].push_back(t[i][j]);
		}
	}
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=n;i++)
		b[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			int tw=a[i][j];
			for(int l=0;l<(int)ra[tw].size();l++){
				int v=ra[tw][l];
				if(!build[v]){
					b[i][v]=MIN(b[i][v],t[i][j]+rt[tw][l]);
					b[v][i]=b[i][v];
				}
			}
		}
		build[i]=1;
	}
	
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=MIN(b[i][j],b[i][l]+b[l][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		long long ans=0x3f3f3f3f3f3f3f3f;
		int x,y;
		scanf("%d %d",&x,&y);
		for(int in=0;in<(int)ra[x].size();in++){
			for(int out=0;out<(int)ra[y].size();out++){
				ans=MIN(ans,
					rt[x][in]
					+b[ra[x][in]][ra[y][out]]
					+rt[y][out]);
				
			}
		}
		ans+=w[x];
		ans+=w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
