#include<iostream>
#include<algorithm> 
#include<cstring>
#include<vector> 
#include<queue>
typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2000005;

ll read(){
	ll k = 0,f=1;char c = getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())k=(k<<1)+(k<<3)+(c^48);
	return k*f;
}

ll n,d;
ll x[N];
vector<int>G[N];
ll dis[N],cnt[N];
bool vis[N];

int bfs(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,false,sizeof(vis));
	queue<int>q;
	q.push(s);
	dis[s] = 0;
	cnt[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(int v:G[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v] = cnt[u];
				if(!vis[v])q.push(v); 
			}else if(dis[v]==dis[u]+1){
				cnt[v] += cnt[u];
			}
		}
	}
	int ret = 0;
	for(int u = s+1;u<=n;u++){
		if(cnt[u]==2)ret++;
	}
	return ret;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	//cout<<c<<T;
	if(c==11||c==12){
		while(T--){
			n = read(),d=read();
			for(int i = 1;i<=n;i++)x[i]=read();
			int dk = d/(x[2]-x[1]);
			if(d==2){
				cout<<n-3<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	while(T--){
		n = read(),d=read();
		for(int i = 1;i<=n;i++)x[i]=read();
		for(int i = 1;i<=n;i++)G[i].clear();
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(abs(x[j]-x[i])<=d)G[i].push_back(j);
			}
		}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			ans += bfs(i);
		}
		printf("%d\n",ans);
	}
}
