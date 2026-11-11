#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int in(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int c,n,m,d,t,k[505];
ll dis[505],dp[505][505],s[505][2],w[500005];
struct node{int y;ll val;};
vector<node>g[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in(),n=in(),m=in(),d=in(),t=in();
	memset(dp,0x3f,sizeof dp);
	for (int i=1;i<=m;i++)w[i]=in();
	for (int i=1;i<=n;i++){
		k[i]=in();dp[i][i]=0;
		for (int j=1;j<=k[i];j++){
			int x=in(),y=in();
			g[x].push_back({i,y});
		}
	}
	for (int i=1;i<=m;i++){
		int cnt=0;
		for (node tmp:g[i]){
			s[++cnt][0]=tmp.y;
			s[cnt][1]=tmp.val;
		}
		for (int j=1;j<=cnt;j++)
			for (int l=1;l<=cnt;l++)
				dp[s[l][0]][s[j][0]]=dp[s[j][0]][s[l][0]]=min(dp[s[j][0]][s[l][0]],s[j][1]+s[l][1]);
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while (t--){
		int x=in(),y=in();
		ll ans=1e18;
		for (node tmp1:g[x])
			for (node tmp2:g[y]){
				ans=min(ans,tmp1.val+tmp2.val+dp[tmp1.y][tmp2.y]);
			}
		printf ("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int in(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int c,n,m,d,t,w[500005],k[505],s[505][2];
ll dis[505];
bool vis[505];
struct node{int y;ll val;};
vector<node>v[505],g[500005];
struct edge{int pos;ll val;};
priority_queue<edge>q;
bool operator<(edge a,edge b){return a.val>b.val;}
inline void dij(){
	for (int i=0;i<=n+1;i++)vis[i]=0,dis[i]=1e18;
	dis[0]=0;
	q.push({0,0});
	while (!q.empty()){
		int x=q.top().pos;q.pop();
		if (vis[x])continue;
		vis[x]=1;
		for (node tmp:v[x]){
			int y=tmp.y;ll val=tmp.val;
			if (dis[y]>dis[x]+val){
				dis[y]=dis[x]+val;
				q.push({y,dis[y]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in(),n=in(),m=in(),d=in(),t=in();
	for (int i=1;i<=m;i++)w[i]=in();
	for (int i=1;i<=n;i++){
		k[i]=in();
		for (int j=1;j<=k[i];j++){
			int x=in(),y=in();
			g[x].push_back({i,y});
		}
	}
	for (int i=1;i<=m;i++){
		int cnt=0;
		for (node tmp:g[i]){
			s[++cnt][0]=tmp.y;
			s[cnt][1]=tmp.val;
		}
		for (int j=1;j<=cnt;j++)
			for (int l=1;l<=cnt;l++){
				if (l!=j){
					v[s[j][0]].push_back({s[l][0],s[j][1]+s[l][1]});
					v[s[l][0]].push_back({s[j][0],s[j][1]+s[l][1]});
				}
			}
	}
	while (t--){
		int x=in(),y=in();
		for (node tmp:g[x])v[0].push_back({tmp.y,tmp.val});
		for (node tmp:g[y])v[tmp.y].push_back({n+1,tmp.val});
		dij();
		printf ("%lld\n",w[x]+w[y]+dis[n+1]);
		for (node tmp:g[y])v[tmp.y].pop_back();
		v[0].clear();
	}
	return 0;
}
*/
