#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN=1e2+5,MAXM=4e2+5,MAXSM=3e2+5;

struct node{
	int v,ln;
};


int c,n,m,d,q,w[MAXN],t[MAXSM],len,ot[MAXN][MAXM];
vector<node> e[MAXM];
vector <int> fl[MAXM];
ll dis[MAXM][MAXSM][MAXN];

void bfs(int s){
	queue<node> q;
	for(int i=0;i<fl[s].size();i++){
		q.push({s,fl[s][i]});
		dis[s][s][fl[s][i]]=min(dis[s][s][fl[s][i]],1LL*ot[fl[s][i]][s]);
	}
	while(!q.empty()){
		int u=q.front().v,bln=q.front().ln;
		q.pop();
		for(int i=0;i<e[u].size();i++){
			if(e[u][i].ln==bln){
				if(dis[s][e[u][i].v]>dis[s][u]){
					dis[s][e[u][i].v][bln]=dis[s][u][bln];
					q.push({e[u][i].v,bln});
				}
			}else{
				int nw=ot[bln][u]+ot[e[u][i].ln][u];
				if(dis[s][e[u][i].v]>dis[s][u]+nw){
					dis[s][e[u][i].v][e[u][i].ln]=dis[s][u][bln]+nw;
					q.push({e[u][i].v,e[u][i].ln});
				}
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		int lst=0;
		for(int j=1;j<=k;j++){
			int now,nt;
			scanf("%d",&now);
			scanf("%d",&ot[i][now]);
			if(j!=1){
				e[lst].push_back({now,i});
				e[now].push_back({lst,i});
			}
			fl[now].push_back(i);
			lst=now;
		}
	}
	for(int i=1;i<=m;i++){
		bfs(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		
		ll ans=1LL*1e9*1e9;
		for(int j=1;j<=100;j++){
			if(ans>dis[x][y][j]+w[x]+w[y]+ot[j][y]){
				ans=dis[x][y][j]+w[x]+w[y]+ot[j][y];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
