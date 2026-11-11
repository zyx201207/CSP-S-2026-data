#include<bits/stdc++.h>
using namespace std;
#define N 1000005
inline int in(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,c,t,ans,dis[505][505],a[N];
vector<int>v[N];
bool vis[N];
struct node{int pos,step;};
queue<node>q;
inline bool work(){
	for (int i=1;i<=n;i++)vis[i]=0;
	int cnt=2;
	for (int i=1;i<=n;i++)if (!vis[i]&&a[i]){q.push({i,0});vis[i]=1;break;}
	while (!q.empty()){
		int x=q.front().pos;q.pop();
		for (int y:v[x]){
			if (a[y]&&!vis[y]){
//				printf ("%d %d\n",y,cnt);
				vis[y]=1;
				q.push({y,0});
				cnt+=a[y];
			}
		}
	}
	for (int i=1;i<=n;i++)if (!vis[i]&&a[i]){q.push({i,0});vis[i]=1;break;}
	while (!q.empty()){
		int x=q.front().pos;q.pop();
		for (int y:v[x]){
			if (a[y]&&!vis[y]){
//				printf ("%d %d\n",y,cnt);
				vis[y]=1;
				q.push({y,0});
				cnt+=a[y];
			}
		}
	}
//	puts("");
	if (cnt==k)return 1;
	return 0;
}
inline void dfs(int step,int cnt){
//	printf ("%d %d\n",step,cnt);
	if (cnt==k){
		if (work()){
			int cnt=0;
			for (int i=1;i<=n;i++){
				int tmp=1e9;
				for (int j=1;j<=n;j++)if (a[j])tmp=min(tmp,dis[i][j]);
				cnt=max(cnt,tmp);
			}
			ans=min(ans,cnt);
		}
		return ;
	}
	if (step>n)return ;
	dfs(step+1,cnt);
	a[step]=1;
	dfs(step+1,cnt+1);
	a[step]=0;
}
inline void bfs(int x){
	for (int i=1;i<=n;i++)vis[i]=0;
	q.push({x,0});vis[x]=1;dis[x][x]=0;
	while (!q.empty()){
		int pos=q.front().pos,step=q.front().step;q.pop();
		for (int y:v[pos]){
			if (!vis[y]){
				vis[y]=1;
				dis[x][y]=step+1;
				q.push({y,step+1});
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=in(),t=in();
	while (t--){
		n=in(),k=in();ans=1e9;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)	
				dis[i][j]=1e9;
		for (int i=1;i<=n;i++)v[i].clear();
		for (int i=1;i<n;i++){
			int x=in(),y=in();
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i=1;i<=n;i++)bfs(i);
//		for (int i=1;i<=n;i++){
//			for (int j=1;j<=n;j++)	
//				printf ("%d ",dis[i][j]);
//			puts("");
//		}
			
		dfs(1,0);
		printf ("%d\n",ans);
	}
	return 0;
}

