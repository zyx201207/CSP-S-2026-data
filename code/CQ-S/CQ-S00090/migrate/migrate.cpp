#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int c,T;
int x[5000];
int dist[5000],num[5000];
int bfs(int s){
	int res=0;
	for(int i=1;i<=n;i++)dist[i]=num[i]=0;
	queue<pair<int,int>>q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.front().first,dis=q.front().second;
		if(n>=d)break;
		q.pop();
		for(int i=u+1;i<=n;i++){
			if(x[i]-x[u]>d)break;	
			if(dist[i]==dis+1)num[i]++;
			else if(!dist[i])dist[i]=dis+1;
			else if(dist[i]<dis+1)continue;
			q.push({i,dis+1});
		}
	}
	for(int i=s+1;i<=n;i++)if(num[i]==1)res++;
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=bfs(i);
		}
		printf("%lld\n",ans);
		
	}
	return 0;
}
