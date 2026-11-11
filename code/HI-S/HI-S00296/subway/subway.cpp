#include<bits/stdc++.h>
using namespace std;
int cid,n,m,d,qt;
int tadd[500100];
//there are $n$ subway,$m$ station
//each station has less than $d$ subway
//there are $q$ query
int st[500505];
struct edge{
	int to,nxt,val;
};
vector<edge> e;
void add(int x,int y,int z){
	e.push_back((edge){y,st[x],z});
	st[x]=e.size()-1;
	e.push_back((edge){x,st[y],z});
	st[y]=e.size()-1;
}
bool in[500505];
int f[500505][505];
list<int> q;
void spfa(int now){
	f[now][now]=0;
	in[now]=true;
	q.push_back(now);
	while(!q.empty()){
		int ck=q.front();
		q.pop_front();
		in[ck]=false;
		for(int to,i=st[ck];i;i=e[i].nxt){
			to=e[i].to;
			int tmp=f[ck][now]+e[i].val;
			if(tmp<f[to][now]){
				f[to][now]=tmp;
				if(!in[to]){
					in[to]=true;
					q.push_back(to);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&cid,&n,&m,&d,&qt);
	for(int i=1;i<=m;i++){
		scanf("%d",&tadd[i]);
	}
	e.push_back((edge){0,0,0});
	for(int manbo,i=1;i<=n;i++){
		scanf("%d",&manbo);
		for(int to,val,j=1;j<=manbo;j++){
			scanf("%d%d",&to,&val);
			add(i,to+n,val);
		}
	}
	
	memset(f,0x3f,sizeof(f));
	
	for(int i=1;i<=n;i++)spfa(i);
	
	for(int x,y,i=1;i<=qt;i++){
		scanf("%d%d",&x,&y);
		int ans=0x7f7f7f7f;
		for(int j=1;j<=n;j++){
			ans=min(ans,f[x+n][j]+f[y+n][j]);
		}
		printf("%d\n",ans+tadd[x]+tadd[y]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

