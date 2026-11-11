#include<iostream>
#include<algorithm> 
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N = 1000005;

int read(){
	int k = 0,f=1;char c = getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())k=(k<<1)+(k<<3)+(c^48);
	return k*f;
}

int builtin_popcount(int x){
	int cnt = 0;
	while(x){
		cnt+=x&1;
		x>>=1;
	}
	return cnt;
}

vector<int>G[N];
int dis[N],S;
bool vis[N],vis2[N];

int bfs(int s){
	memset(vis,false,sizeof(vis));
	queue<int>q;
	dis[s] = 0;
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		int u =q.front();
		q.pop();
		for(int v :G[u]){
			if(vis[v])continue;
			vis[v] = true;
			dis[v] = dis[u]+1;
			q.push(v);
			if(S>>(v-1)&1)return dis[v];
		}
	} 
}

void dfs(int u,int f){
	vis2[u] = true;
	for(int v :G[u]){
		if(v==f||!(S>>(v-1)&1))continue;
		dfs(v,u);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		int n=read(),k=read();
		for(int i = 1;i<=n;i++)G[i].clear();
		for(int i = 1;i<n;i++){
			int u = read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int ans = 0x3f3f3f3f;
		for(S = 0;S<(1<<n);S++){
			int temp = 0;
			if(builtin_popcount(S)==k){
				int cnter = 0;
				memset(vis2,false,sizeof(vis2));
				for(int i = 1;i<=n;i++){
					if(!vis2[i]&&(S>>(i-1)&1))dfs(i,0),cnter++;
				}
				if(cnter>2)continue;
				for(int i = 1;i<=n;i++){
					if(!(S>>(i-1)&1))temp = max(temp,bfs(i));
				}
				ans = min(temp,ans);
			}
		}
		printf("%d\n",ans);
	}
}
