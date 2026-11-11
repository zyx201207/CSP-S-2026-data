#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int c,m,n,d,q,ti,a[N],head[N],u,v,k,cnt,dis[N],fa[N]={};
bool flag=1,vis[N];
vector<pair<int,int>>t[N];
struct edge{
	int x,y,w,next=0,z;
}e[N];
void add(int x,int y,int z){
	e[++cnt].next=head[x];
	e[cnt].x=x,e[cnt].y=y;
	e[cnt].z=z;
	head[x]=cnt;
}
void disk(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[u]=a[u];
	int minn,mini;
	//mini=1;
	
	for(int i=1;i<n;i++){
			minn=N;
			for(int j=1;j<=n;j++){
				if(minn>dis[j]&&!vis[j])minn=dis[j],mini=j;
			}
			vis[mini]=1;
			//cout<<i<<" "<<mini<<endl;
		for(int j=head[mini];j!=0;j=e[j].next){
			
			if(dis[mini]+e[j].w<dis[e[j].y]){
				dis[e[j].y]=dis[mini]+e[j].w;
				fa[e[j].y]=mini;
			}
		}
	}
	//cout<<1;
	for(int i=v;i!=u;i=fa[i]){
		//cout<<i<<" "<<fa[i]<<endl;
		if(i==v){
			dis[v]+=a[v];
			break;
		}
		for(int j=0;j<t[fa[i]].size();j++){
			if(t[fa[i]][j].first==i){
				dis[v]+=t[fa[i]][j].second;
			}
		}
	}
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		scanf("%d%d",&u,&ti);
		t[u].push_back(make_pair(u,ti));
		for(int j=1;j<k;j++){
			scanf("%d%d",&v,&ti);
			t[u].push_back(make_pair(u,ti));
			add(u,v,i);
			add(v,u,i);
			u=v;
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=head[i];j!=0;j=e[j].next){
			cout<<e[j].y<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++){
		scanf("%d%d",&u,&v);
		
		disk();
		printf("%d",dis[v]);
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
