#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[50005];
int head[20005],num=0,dis[20005],vis[20005],dus[20005];
struct edge{
	int next,to;
}e[5000005];
void add_e(int from,int to){
	e[++num].next=head[from],e[num].to=to,head[from]=num;
}
priority_queue<pair<int,int> > q;
void dij(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,78,sizeof(dis));
	memset(dus,0,sizeof(dus));
	dis[s]=0,dus[s]=1;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int sto=e[i].to;
			if(dis[sto]>dis[u]+1){
				dis[sto]=dis[u]+1,dus[sto]=dus[u];
				q.push({-dis[sto],sto});
			}
			else if(dis[sto]==dis[u]+1) dus[sto]+=dus[u];
			else continue;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]>d) break;
				add_e(i,j),add_e(j,i);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=i+1;j<=n;j++){
				if(dus[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
		num=0;
		memset(head,0,sizeof(head));
		memset(e,0,sizeof(e));
	}
	return 0;
}
