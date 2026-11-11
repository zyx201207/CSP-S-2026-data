#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,H=5005;
const int mod=998244353;
//思路：计算两点之间最短路径数量，对998244353取模
//然后再标记两点最短路径数是否被取模过 
int c,t,n,d,x[N],dist[H][H],vis[N],cnt[H][H],bj[H][H],ans;
struct node{int id,dis;};
vector<node> edge[N];
priority_queue<node> q;
bool operator<(node a,node b){return a.dis>b.dis;}
void distjia(int s){
	for(int i=1;i<=n;i++)dist[s][i]=1e18,vis[i]=0;
	dist[s][s]=0,bj[s][s]=0,cnt[s][s]=1;
	q.push({s,0});
	while(!q.empty()){
		node x=q.top();
		q.pop();
		if(vis[x.id])continue;
		vis[x.id]=1;
		for(auto tx:edge[x.id]){
			if(dist[s][x.id]+tx.dis<=dist[s][tx.id]){
				if(dist[s][x.id]+tx.dis==dist[s][tx.id]){
					cnt[s][tx.id]+=cnt[s][x.id];
					if(cnt[s][tx.id]>998244353){
						cnt[s][tx.id]%=mod;
						bj[s][tx.id]++;
					} 
				}else{
					cnt[s][tx.id]=cnt[s][x.id];
					if(cnt[s][tx.id]>998244353){
						cnt[s][tx.id]%=mod;
						bj[s][tx.id]++;
					} 
				}
			    dist[s][tx.id]=dist[s][x.id]+tx.dis;
			    q.push({tx.id,dist[s][tx.id]});
			}
		}
	} 
}
void sovle(){
	memset(dist,0,sizeof(dist));
	memset(cnt,0,sizeof(cnt));
	memset(bj,0,sizeof(bj));
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++)edge[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(x[j]-x[i])<=d){
				edge[i].push_back({j,1});
				edge[j].push_back({i,1});
			}
		}
	}
	for(int i=1;i<=n;i++)distjia(i);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2)ans++;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)sovle();
	return 0;
}
//难道这道题送24分吗？ 
//时间很紧张啊，目前估计只有100+44+24+15=183，何以一等 
//我去居然感觉会O(n^2)了，这可是40分啊 
//读了半天的假题发现假了，但是又改回来了 
