#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int C,T;
int n,l;
int a[N];
vector<int> mp[N];
bool vis[N];
int d[N],cnt[N];
void bfs(int s){
	for(int i=1;i<=n;i++){
		vis[i]=false;
		d[i]=LONG_LONG_MAX;
		cnt[i]=0;
	}
	queue<int> q;
	q.push(s);
	d[s]=0;
	cnt[s]=1;
//	vis[u]=true;
	while(q.size()){
		int u=q.front();
		q.pop();
//		if(vis[u]) continue;
		for(int i=0;i<mp[u].size();i++){
			int v=mp[u][i];
//			if(vis[v]) continue;
			if(d[v]<d[u]+1) continue;
			cnt[v]+=cnt[u];
			q.push(v);
			d[v]=d[u]+1;
//			vis[v]=true;
		}
	}
//	printf("\n");
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&l);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//		for(int i=1;i<=n;i++) printf("%lld ",a[i]);
		for(int i=1;i<=n;i++){
			mp[i].clear();
		}
		for(int i=1;i<=n;i++){
			int j=i+1;
			while((j<=n)&&(a[j]-a[i]<=l)){
				mp[i].push_back(j);
				j++;
			}
		}
//		for(int i=1;i<=n;i++){
//			printf("%lld: ",i);
//			for(int j=0;j<mp[i].size();j++){
//				printf("%lld ",mp[i][j]);
//			}
//			printf("\n");
//		}
		int ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++){
//				printf("%lld ",cnt[j]);
				if(cnt[j]==2) ans++;
			}
//			printf("\n");
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

0
1

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1

*/
