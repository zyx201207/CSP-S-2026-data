#include<bits/stdc++.h>
using namespace std;
int n,d;
__int128 ac[2000005];
int dp[2000005];
long long fa[2000005];
int be[2000005];
long long abs(__int128 x){
	return (x<0 ? -x : x);
}
void bfs(int bew){
	queue<int>q;
	q.push(bew);
	fa[bew]=1;
	dp[bew]=1;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int j=be[v];abs(ac[j]-ac[v])<=d&&j<=n;j++){
			if(j!=v){
				if(!dp[j]){
					dp[j]=dp[v]+1;
					q.push(j);
					fa[j]+=fa[v];
				}else if(dp[j]==dp[v]+1){
					fa[j]+=fa[v];
				}
			}
		}
	}
}
int main(){
	int c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			long long t;
			scanf("%lld",&t);
			ac[i]=t;
			be[i]=lower_bound(ac+1,ac+i+1,ac[i]-d)-ac;
		}
		long long an=0;
		for(int i=1;i<=n;i++){
			memset(dp,0,sizeof(dp));
			memset(fa,0,sizeof(fa));
			bfs(i);
			for(int j=1;j<=n;j++){
				if(fa[j]==2){
					an++;
				}
			}
		}
		printf("%lld\n",an/2);
	}
	return 0;
}
