#include<bits/stdc++.h>
using namespace std;
#define N 505
#define M 500005
typedef long long ll;
int c,n,m,d,q;
ll w[M];
int k[N];
vector<int> road[N];
struct node{
	int road_num;
	ll wal_tim;
};
vector<node> tim[M];
ll tran[N][N],dis[N][N];
void init(){
	memset(tran,0x3f,sizeof(tran));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		tran[i][i]=0;
	}
}
void solv(int u){
	int len=tim[u].size();
	int fro,to;
	ll wt1,wt2;
	for(int i=0;i<len;i++){
		fro=tim[u][i].road_num;
		wt1=tim[u][i].wal_tim;
		for(int j=i+1;j<len;j++){
			to=tim[u][j].road_num,wt2=tim[u][j].wal_tim;
			tran[fro][to]=min(tran[fro][to],wt1+wt2);
			tran[to][fro]=min(tran[to][fro],wt1+wt2);
		}
	}
}
struct inqu{
	int s,d;
}ans[100005];
void deal(int u,int v){
	int len1=tim[u].size(),len2=tim[v].size();
	ll fin_ans=dis[0][0],v1,v2;
	int fro,to,flag=0;
	for(int i=0;i<len1;i++){
		if(flag){
			break;
		}
		fro=tim[u][i].road_num;
		v1=tim[u][i].wal_tim;
		for(int j=0;j<len2;j++){
			to=tim[v][j].road_num,v2=tim[v][j].wal_tim;
			fin_ans=min(fin_ans,dis[fro][to]+v1+v2);
		}
	}
	fin_ans+=w[u];
	fin_ans+=w[v];
	printf("%lld\n",fin_ans);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	int sta;
	ll wal;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%lld",&sta,&wal);
			road[i].push_back(sta);
			tim[sta].push_back({i,wal});
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&ans[i].s,&ans[i].d);
	} 
	init();
	for(int i=1;i<=m;i++){
		if(tim[i].size()>1){
			solv(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=tran[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int h=1;h<=n;h++){
				dis[i][j]=min(dis[i][j],dis[i][h]+dis[h][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		deal(ans[i].s,ans[i].d);
	}
	
	return 0;
} 
