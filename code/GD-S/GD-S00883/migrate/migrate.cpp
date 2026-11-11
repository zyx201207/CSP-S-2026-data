#include<stdio.h>
#include<set>
#include<queue>
#include<vector>

static inline void swap(int * f,int * s){
	if(*f==*s || f==s){
		return ;
	}
	*f^=*s;
	*s^=*f;
	*f^=*s; 
}

static inline long long int abs(long long int param){
	if(param>0) return param;
	else return -param;
}

const long long int inf=(1ll<<62);

long long int p[(int)2e6+5];
long long int d;
long long int map[5005][5005];
long long int dis[5005];
long long int cnt[5005];
int n;

static inline void bfs(int begin){
	std::queue<int> q;
	std::vector<bool> vis(n+1,false);
	for(int i=1;i<=n;i++){
		dis[i]=inf;
	} 
	q.push(begin);
	dis[begin]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]==true){
			continue;
		}
		vis[u]=true;
		for(int i=1;i<=n;i++){
			if(abs(p[i]-p[u])>d){
				continue;
			}
			if(vis[i]==true){
				continue;
			}
			if(dis[i]<dis[u]+1){
				continue;
			}
			dis[i]=dis[u]+1;
			q.push(i);
		}
	}
}

static void dfs(int source,int now,int length){
	if(length>map[source][now]){
		return ;
	}
	if(length==map[source][now]){
		cnt[now]++;
	}
	for(int i=1;i<=n;i++){
		if(abs(p[now]-p[i])>d){
			continue;
		}
		dfs(source,i,length+1);
	}
	return ;
}

static inline void solve(void){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			map[i][j]=0;
		}
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&p[i]);
	}
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=1;j<=n;j++){
			map[i][j]=dis[j];
		}
	}
	std::set<std::pair<int,int> > pair;
	for(int i=1;i<=n;i++){
		dfs(i,i,0);
		for(int j=1;j<=n;j++){
			if(cnt[j]==2){
				int l=i,r=j;
				if(l>r){
					swap(&l,&r);
				}
				pair.insert({l,r});
			}
			cnt[j]=0;
		}
	}
	printf("%lld\n",pair.size());
	return ;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}
