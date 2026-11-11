#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=510,M=510000;
const long long inf=1000000000000000000;
int c,n,m,d,q,k;
long long w1[M],dis[N][N],ans;
vector<pair<int,long long> >e[M];
inline int read(){
	char c=getchar();
	while(!('0'<=c&&c<='9'))c=getchar();
	int s=0;
	while('0'<=c&&c<='9')s=s*10+c-'0',c=getchar();
	return s;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w1[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1,u,w;j<=k;j++){
			u=read(),w=read();
			e[u].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		k=e[i].size();
		for(int j1=0;j1<k;j1++){
			for(int j2=0;j2<k;j2++){
				dis[e[i][j1].first][e[i][j2].first]=min(dis[e[i][j1].first][e[i][j2].first],e[i][j1].second+e[i][j2].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int x,y,k1,k2;
		x=read(),y=read();
		ans=inf;
		k1=e[x].size(),k2=e[y].size();
		for(int i=0;i<k1;i++){
			for(int j=0;j<k2;j++){
				ans=min(ans,w1[x]+w1[y]+e[x][i].second+e[y][j].second+dis[e[x][i].first][e[y][j].first]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
