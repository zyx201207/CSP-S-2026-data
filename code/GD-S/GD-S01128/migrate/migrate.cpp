#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10,M=3e7+10;
int c,t,n;
ll d,x[N],dis[N],cnt[N],ans=0;
bool vis[5002][5002],tag[N];
struct Node{
	int id;
	ll d;
	bool operator<(const Node &other)const{
	    return d>other.d;
	}
};
priority_queue<Node>q;
vector<int>e[N];
//void add(int u,int v){
//	To[++tot]=v;
//	//W[tot]=w;
//	Nxt[tot]=Head[u];
//	Head[u]=tot;
//}
void dij(int s){
	for(int i=1;i<=n;i++){
		dis[i]=0x3f3f3f3f;
	} 
	for(int i=1;i<=n;i++){
		cnt[i]=0;
		tag[i]=false;
	}
	while(!q.empty())q.pop();
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		int cur=q.top().id;
		if(tag[cur]){
			q.pop();
			continue;
		}
		tag[cur]=true;
		q.pop();
		for(auto v:e[cur]){
			//printf("BB\n");
			if(dis[v]>dis[cur]+1){
				//printf("AA\n");
				dis[v]=dis[cur]+1;
				cnt[v]=1;
				q.push({v,dis[v]});
			}
			else if(dis[v]==dis[cur]+1){
				cnt[v]++;
			}
		}
	}
//	printf("c:\n");
//	for(int i=1;i<=n;i++){
//		printf("%d ",dis[i]);
//	}
	//printf("\n");
	for(int i=1;i<=n;i++){
		if(cnt[i]==2&&(!vis[i][s])&&(!vis[s][i])){
			++ans;
			vis[s][i]=true;
			//printf("A:%lld %d %d\n",dis[i],s,i);
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		memset(vis,false,sizeof(vis));
	    scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(n>5000){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ll l=llabs(x[i]-x[j]);
				if(l<=d&&i!=j){
					e[i].push_back(j);
					e[j].push_back(i);
					//printf("AA%d %d\n",i,j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			//printf("AA\n");
			dij(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
