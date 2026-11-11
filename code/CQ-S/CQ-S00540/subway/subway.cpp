#include<bits/stdc++.h>
#define fre(ss,i,j,k) for(int ss=i;ss<=j;ss+=k)
#define rep(ss,i,j,k) for(int ss=i;ss>=j;ss-=k)
using namespace std;
const int N=5e2+5,M=5e5+5;
int C,n,m,D,Q,a[M];
vector<pair<int,int>>xl[M];
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&D,&Q);
	fre(i,1,m,1)scanf("%d",&a[i]);
	fre(i,1,n,1){
		int num;scanf("%d",&num);
		fre(j,1,num,1){
			int id,val;scanf("%d%d",&id,&val);
			xl[id].push_back({i,val});
		}
	}
	memset(dis,0x3f,sizeof dis);
	fre(i,1,m,1)for(auto [x,vx]:xl[i])for(auto [y,vy]:xl[i])
		dis[x][y]=dis[y][x]=min(dis[x][y],1ll*vx+vy);
	fre(i,1,n,1)dis[i][i]=0;
	fre(k,1,n,1)fre(i,1,n,1)fre(j,1,n,1)if(dis[i][k]+dis[k][j]<dis[i][j])
		dis[i][j]=dis[i][k]+dis[k][j];
	while(Q--){
		int x,y;scanf("%d%d",&x,&y);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto [idx,vx]:xl[x])for(auto [idy,vy]:xl[y])
			ans=min(ans,dis[idx][idy]+vx+vy);
		printf("%lld\n",ans+a[x]+a[y]);
	}
	return 0;
}
