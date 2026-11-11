#include<bits/stdc++.h>
using namespace std;
long long c,t,di[2000005],dis[2000005],head[2000005],cnt=0,vis[2000005],ans[2000005],pro=0,n,d;
struct node{
	long long to,nxt,dp;
}edge[5000005];
void add(long long u,long long v,long long dd){
	cnt++;
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	edge[cnt].dp=dd;
	head[u]=cnt;
}
priority_queue<pair<long long,long long> > q;
void dij(long long st){
	for(int i=1;i<=n;i++){
		dis[i]=3e18,vis[i]=0;
	}
	dis[st]=0;
	q.push(make_pair(0,st));
	while(!q.empty()){
		long long u=q.top().second;
		q.pop();
		if(vis[u]==1){
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].nxt){
			long long hh=dis[u]+edge[i].dp;
			if(dis[edge[i].to]>hh){
				dis[edge[i].to]=hh;
				q.push(make_pair(-dis[edge[i].to],edge[i].to));
				ans[edge[i].to]=ans[u];
			}else if(dis[edge[i].to]==hh){
				ans[edge[i].to]+=ans[u]; 
			}
		}
	}
}
void solve(int tp){
	for(int i=1;i<=n;i++){
		ans[i]=0;
	}
	ans[tp]=1;
	dij(tp);
	for(int i=tp+1;i<=n;i++){
		if(ans[i]==2){
//			cout<<tp<<" "<<i<<endl;
			pro++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&di[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long tpp=di[j]-di[i];
				if(tpp<=d){
					add(i,j,1);
				}
			}
		}
		for(int i=1;i<=n;i++){
			solve(i);
		}
		printf("%lld\n",pro);
		for(int i=1;i<=cnt;i++){
			edge[i].to=0,edge[i].nxt=0,edge[i].dp=0;
		}
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		pro=0,cnt=0;
	}
	return 0;
}

