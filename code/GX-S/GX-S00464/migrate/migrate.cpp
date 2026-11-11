#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+10,maxm=5e3+10;
int c,t,n,m,dis[maxn],cnt[maxn];
int d,x[maxn];
vector<int>g[maxm];
bool vis[maxn];
void dijkstra(int s){
	queue<int>q;
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	cnt[s]=1,dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(vis[x])
			continue;
		vis[x]=true;
		for(int i=0;i<g[x].size();i++){
			int to=g[x][i];
			//cout<<dis[to]<<" "<<dis[x]<<" "<<to<<" "<<x<<"\n";
			if(dis[to]>dis[x]+1){
				cnt[to]=1;
				dis[to]=dis[x]+1;
				if(!vis[to])
					q.push(to);
			}
			else if(dis[to]==dis[x]+1)
				cnt[to]++;
		}
	}
}
void solve(){
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n&&abs(x[j]-x[i])<=d;j++)
			g[j].push_back(i),g[i].push_back(j);
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=i+1;j<=n;j++)
			ans+=cnt[j]==2;
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
		g[i].clear();
}
void solveA(){
	int D=x[2]-x[1],step=d/D,ans=0;
	if(step!=2)
		printf("0\n");
	else{
		for(int i=1;i<=n;i++)
			if(i+step<=n)
				ans++;
		printf("%lld\n",ans);
	}
}
void solveB(){
	int ans=0;
	for(int i=1,l=1,r=1;i<=n;i++){
		int R=r;
		l=i;
		while(r<=n&&x[r]-x[R]<=d)
			r++;
		r--;
		while(l<=n&&x[l]-x[i]<=d)
			l++;
		ans+=(r-l+1);
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		if(n<=5000)
			solve();
		else if(c==11||c==12)
			solveA();
		else if(c==13||c==14)
			solveB();
	}
	return 0;
}
