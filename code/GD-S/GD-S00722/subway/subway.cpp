#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
	return x*f;
}
void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int maxn=5e2+5,maxm=5e4+5;
const ll inf=1e18;
int n,m,d,q,t[maxn][maxm],x,y;
ll w[maxm],dis[maxm][maxn];
bool pasted[maxm][maxn],vis[maxm][maxn];
struct node{
	int d,u,id;
};
vector<node>g[maxm][maxn];
void spfa(int s){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=m;i++)for(int j=0;j<=n;j++)dis[i][j]=inf;
	queue<node>q;
	int mi=1;
	for(int i=1;i<=n;i++){
		if(pasted[s][i]&&t[i][s]<dis[s][0]){
			dis[s][0]=t[i][s];
			mi=i;
		}
	}
	vis[s][mi]=1;
	q.push({dis[s][0],s,mi});
	for(int i=1;i<=n;i++)
		if(pasted[s][i]){
			dis[s][i]=0;
			vis[s][i]=1;
			q.push({0,s,i});
		}
	while(!q.empty()){
		int u=q.front().u,id=q.front().id;
		q.pop();
		for(int i=0;i<g[u][id].size();i++){
			int v=g[u][id][i].u,vid=g[u][id][i].id,w=g[u][id][i].d;
			if(dis[v][vid]>dis[u][id]+w){
				dis[v][vid]=dis[u][id]+w;
				if(!vis[v][vid]){
					vis[v][vid]=1;
					q.push({dis[v][vid],v,vid});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read();
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	vector<int>a[maxn];
	for(int i=1;i<=n;i++){
		int k=read();
		a[i].resize(k+1); 
		for(int j=1;j<=k;j++){
			a[i][j]=read();
			if(j>1){
				g[a[i][j]][0].push_back({0,a[i][j-1],0});
				g[a[i][j-1]][0].push_back({0,a[i][j],0});
			}
			pasted[a[i][j]][i]=1;
			t[i][a[i][j]]=read();
		}
	}
	for(int i=1;i<=m;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n;k++){
		if(j==k)continue;
		if(j!=0&&k!=0&&(!pasted[i][j]||!pasted[i][k]))continue;
		g[i][j].push_back({t[j][i]+t[k][i],i,k});
		g[i][k].push_back({t[j][i]+t[k][i],i,j});
	}
	while(q--){
		x=read(),y=read();
		ll ans1=inf,ans2=inf;
		for(int i=1;i<=n;i++)if(pasted[x][i])ans1=min(ans1,(ll)t[i][x]);
		for(int i=1;i<=n;i++)if(pasted[y][i])ans2=min(ans2,(ll)t[i][y]);
		write(ans1+ans2);
		putchar('\n');
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
