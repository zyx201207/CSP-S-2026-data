#include <cstdio>
#include <cstring>
long long dist[501][501];
int transfer[500001][21][2];
int station[500001];
int min(int a,int b){
    return a<b?a:b;
}
long long min(long long a,long long b){
    return a<b?a:b;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i) scanf("%d",station+i);
    for(int i=1;i<=n;++i){
	int tot,tmp,time;
	scanf("%d",&tot);
	for(int j=0;j<tot;++j){
	    scanf("%d%d",&tmp,&time);
	    transfer[tmp][++transfer[tmp][0][0]][0]=i;
	    transfer[tmp][transfer[tmp][0][0]][1]=time;
	}
    }
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;++i) dist[i][i]=0ll;
    for(int i=1;i<=m;++i){
	int tmp=transfer[i][0][0];
	for(int j=1;j<=tmp;++j){
	    for(int k=j+1;k<=tmp;++k){
#define wayi transfer[i][j][0]
#define wayj transfer[i][k][0]
		dist[wayi][wayj]=dist[wayj][wayi]=
		    min(dist[wayi][wayj],(long long)transfer[i][j][1]+transfer[i][k][1]);
	    }
	}
    }
    for(int k=1;k<=n;++k){
	for(int i=1;i<=n;++i){
	    for(int j=1;j<=n;++j){
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	    }
	}
    }
    while(q--){
	int x,y;
	scanf("%d%d",&x,&y);
	long long ans=0x7fffffffffffffff;
	for(int i=1;i<=transfer[x][0][0];++i){
	    for(int j=1;j<=transfer[y][0][0];++j){
		ans=min(ans,dist[transfer[x][i][0]][transfer[y][j][0]]+transfer[x][i][1]+transfer[y][j][1]);
	    }
	}
	printf("%lld\n",ans+station[x]+station[y]);
    }
}
