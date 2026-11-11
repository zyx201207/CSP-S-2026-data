#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int e,d;
};
int c,t,n,d,x[2000005],ans,cnt[2000005],minn[2000005];
vector<int> g[2000005];
queue<node> q;
void bfs(int s,int y){
	q.push({s,0});
	while(!q.empty()){
		node u=q.front();
		q.pop();
		if(u.d==minn[u.e]) cnt[u.e]++;
		if(cnt[u.e]==0) minn[u.e]=u.d,cnt[u.e]++;
		if(cnt[u.e]>2){
			cnt[y]=0;
			return ;
		}
		for(auto gi:g[u.e]){
			q.push({gi,u.d+1});
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		ans=0;
		memset(x,0,sizeof x);
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])<=d) g[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(minn,0x7f,sizeof minn);
				memset(cnt,0,sizeof cnt);
				bfs(i,j);
				if(cnt[j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
