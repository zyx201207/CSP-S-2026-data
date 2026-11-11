#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int k[N];
bool b[N];
vector<pair<int,ll> >a[N];
ll dis[N],w[N],ans[N];
bool vis[N];
queue<int>qq;
struct Node{
	int x,y,id;
}cc[N];
void spfa(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(qq.size())qq.pop();
	qq.push(x);
	dis[x]=0;
	while(qq.size()){
		int u=qq.front();qq.pop();
		vis[u]=0;
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i].first;
			int w=a[u][i].second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					qq.push(v);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i==x)continue;
		dis[i]=dis[i]+w[i]+w[x];
	}
}
bool cmp(Node x,Node y){
	return x.x<y.x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		memset(b,0,sizeof(b));
		for(int j=1;j<=k[i];j++){
			int x,t;
			scanf("%d %d",&x,&t);
			b[x]=1;
			a[m+i].push_back({x,t});
			a[x].push_back({m+i,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		cc[i].x=x;cc[i].y=y;cc[i].id=i;
	}
	sort(cc+1,cc+1+q,cmp);
	int tnt=0;
	for(int i=1;i<=q;i++){
		if(tnt!=cc[i].x){
			spfa(cc[i].x);
			tnt=cc[i].x;
		}
		ans[cc[i].id]=dis[cc[i].y];
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
} 
