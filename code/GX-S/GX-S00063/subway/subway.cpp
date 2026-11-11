#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
struct node{
	int a,w;
	bool operator<(const node b)const {
		return w>b.w;
	}
};
struct node2{
	int x,y,id;
}e[N];
vector<node> g[N];
int w[N],k[N],dist[N],x[N],y[N],vis[N];
long long ans[N];
bool cmp(node2 a,node2 b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
void dijisktra(int st){
	memset(dist,0x3f3f3f3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	dist[st]=0;q.push({st,0});
	while(!q.empty()){
		node u=q.top();q.pop();
		if(vis[u.a])continue;
		vis[u.a]=1;
		for(auto&i:g[u.a]){
			//cout<<i.a<<"\n";
			if(vis[i.a])continue;
			if(dist[i.a]>dist[u.a]+i.w){
				dist[i.a]=dist[u.a]+i.w;
				//cout<<i.a<<" "<<dist[i.a]<<" "<<u.a<<"\n";
				q.push({i.a,dist[i.a]});
			}
		}
	}
	//for(int i=1;i<=10;++i)cout<<dist[i]<<"\n";
}
void write(int s){
	if(s<0){
		s=-s;
	}
	if(s>10){
		write(s/10);
	}
	putchar(s%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		k[i]=read();
		int na=0;
		for(int j=1;j<=k[i];++j){
			int a=read(),t=read();g[a+m*i].push_back({a,t});g[a].push_back({a+m*i,t});
			if(j!=1){
				g[na+m*i].push_back({a+m*i,0});g[a+m*i].push_back({na+m*i,0});	
			}na=a;
		}
	}
	for(int i=1;i<=q;++i){
		e[i].x=read();e[i].y=read();e[i].id=i;
	}
	stable_sort(e+1,e+q+1,cmp);
	for(int i=1;i<=q;++i){
		if(e[i].x!=e[i-1].x){
			dijisktra(e[i].x);
		}
		ans[e[i].id]=w[e[i].x]+w[e[i].y]+dist[e[i].y];
	}
	for(int i=1;i<=q;++i){
		write(ans[i]);putchar('\n');
	}
	return 0;
}
