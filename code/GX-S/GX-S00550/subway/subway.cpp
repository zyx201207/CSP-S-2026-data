#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
const long long inf=1e18;
int c,n,m,d,q;
int w[N];
int head[N],nxt[N<<1],to[N<<1],cnt;
long long v[N<<1];
void edge(int x,int y,long long z){
	to[++cnt]=y;v[cnt]=z;nxt[cnt]=head[x];head[x]=cnt;
}
long long dis1[N];
bool vis[N];
long long dis2[505][505];
struct op{
	int h;
	long long vh;
	bool operator <(const op &x)const{return vh>x.vh;}
};
struct zbl{
	int e;
	long long r;
}p[N][30];
priority_queue<op> qd;
void dij(int s){
	for(int i=1;i<=m+n+1;i++)vis[i]=0;
	for(int i=1;i<=m+n+1;i++)dis1[i]=inf;
	qd.push({s,0});
	dis1[s]=0;
	while(!qd.empty()){
		op x=qd.top();
		qd.pop();
		if(vis[x.h])continue;
		vis[x.h]=1;
		for(int i=head[x.h];i;i=nxt[i]){
			if(dis1[to[i]]>dis1[x.h]+w[i]&&!vis[to[i]]){
				dis1[to[i]]=dis1[x.h]+v[i];
				qd.push({to[i],dis1[to[i]]});
			}
		}
	}
	//for(int i=1;i<=n+m;i++)cout<<dis1[i]<<" ";
	//cout<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			p[x][++p[x][0].e].e=i;
			p[x][p[x][0].e].r=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=p[i][0].e;j++){
			for(int k=1;k<=p[i][0].e;k++){
				if(j!=k){
					edge(p[i][j].e+m,p[i][k].e+m,p[i][j].r+p[i][k].r);
					edge(p[i][k].e+m,p[i][j].e+m,p[i][j].r+p[i][k].r);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i+m);
		for(int j=1;j<=n;j++){
			dis2[i][j]=dis1[j+m];
			//cout<<dis2[i][j]<<" ";
		}
		//cout<<endl;
	}
	while(q--){
		int s,t;
		scanf("%d%d",&s,&t);
		long long ans=inf;
		for(int i=1;i<=p[s][0].e;i++){
			for(int j=1;j<=p[t][0].e;j++){
				ans=min(ans,p[s][i].r+p[t][j].r+dis2[p[s][i].e][p[t][j].e]);
			}
		}
		ans+=w[s]+w[t];
		printf("%lld\n",ans);
	}
	return 0;
}
