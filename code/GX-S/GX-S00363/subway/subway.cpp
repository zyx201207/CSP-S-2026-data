#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000010],t[100010][21],k[1000010],x[100010][21],len[100010],dt[100010][21];
struct E{int to,next,line;}e[1000010];
int head[1000010],dis[100010][21],vis[1000010],tot=0;
void add(int u,int v,int l){e[++tot].to=v;e[tot].next=head[u];head[u]=tot;e[tot].line=l;}
struct points{int p,l;};
void dijkstra(int st){
	queue<points> q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=len[st];i++){dis[st][dt[st][i]]=t[st][dt[st][i]];q.push((points){st,dt[st][i]});}
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		points tmpp=q.front();q.pop();
		int tmp=tmpp.p,li=tmpp.l;
		if(vis[tmp])continue;
		vis[tmp]=1;
		for(int i=head[tmp];i;i=e[i].next){
			int sum=dis[tmp][li];//cout<<dis[tmp][li]<<endl;
			if(e[i].line!=li){sum+=t[tmp][li]+t[tmp][e[i].line];}
			//cout<<tmp<<" "<<li<<" "<<e[i].to<<" "<<e[i].line<<" "<<sum<<" "<<dis[e[i].to][e[i].line]<<endl;
			if(dis[e[i].to][e[i].line]>sum){dis[e[i].to][e[i].line]=sum;q.push((points){e[i].to,e[i].line});}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int y;scanf("%d%d",&x[i][j],&y);
			t[x[i][j]][i]=y;
			dt[x[i][j]][++len[x[i][j]]]=i;
			if(j>=2){add(x[i][j],x[i][j-1],i);add(x[i][j-1],x[i][j],i);}
		}
	}
	for(int i=1;i<=q;i++){
		int xx,yy,ans=INT_MAX;
		cin>>xx>>yy;
		//cout<<xx<<" "<<yy<<" B "<<q<<endl;
		dijkstra(xx);
		for(int j=1;j<=len[yy];j++)ans=min(ans,w[xx]+dis[yy][dt[yy][j]]+t[yy][dt[yy][j]]+w[yy]);
		cout<<ans<<endl;
	}
	return 0;
}
//weile pian 32pts huale jige xiaoshi 67676767676767
//RP+=G(64)
