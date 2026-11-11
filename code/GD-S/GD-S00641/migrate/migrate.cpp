#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,M=1e6+5;
typedef pair<int,int> pii;
int n,pos[N],idx=1,h[M<<1],c,t,d,dis[N],cnt[N],ans;
struct edge{
	int v,w,ne;
}e[M<<1];
void add(int from,int to,int w){
	e[++idx]={to,w,h[from]};
	h[from]=idx;
}
void dijk(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	dis[s]=0;cnt[s]=1;
	priority_queue<pii> q;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		for(int i=h[u];i;i=e[i].ne){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				cnt[v]+=cnt[u];
				q.push(make_pair(-dis[v],v));
			}
			else if (dis[v]==dis[u]+w){
				cnt[v]+=cnt[u];
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for (int i=1;i<=n;i++) scanf("%lld",&pos[i]);
		memset(h,0,sizeof(h));
		idx=1;
		for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			if (pos[j]-pos[i]<=d) add(i,j,1);
		}
		for (int s=1;s<=n;s++)
		for (int t=s+1;t<=n;t++){
			dijk(s);
			if (cnt[t]==2) ans++;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
