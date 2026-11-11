#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],n;
vector<int> G[5005];
int cnt[5005],dis[5005];
int A[5005][5005];
void bfs(int x){
	queue<int> q;
	q.push(x);
	memset(cnt,0,sizeof(cnt));
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0,cnt[x]=1;
//	for(int i=1; i<=n; i++) cnt[i]=1;
	while(q.size()){
		int now=q.front();
		q.pop();
		for(int i=0; i<(int)G[now].size(); i++){
			int tx=G[now][i];
			if(dis[tx]==dis[now]-1){
				cnt[now]+=cnt[tx];
			}
		}
		for(int i=0; i<(int)G[now].size(); i++){
			int tx=G[now][i];
			if(dis[tx]>dis[now]+1){
				dis[tx]=dis[now]+1;
//				cnt[tx]=1;
				q.push(tx);
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,q;
	scanf("%lld %lld",&c,&q);
	while(q--){
		memset(a,0,sizeof(a));
		int d;
		scanf("%lld %lld",&n,&d);
		for(int i=1; i<=n; i++){
			scanf("%lld",&a[i]);
//			cout<<a[i]<<endl;
		}
//		sort(a+1,a+n+1);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				int t=a[j]-a[i];
//				if(t<0) t=-t;
				if(abs(t)<=d){
					G[i].push_back(j);
//					G[j].push_back(i);
				}
			}
		}
//		for(int i=1; i<=n; i++){
//			for(int j=0; j<G[i].size(); j++){
//				printf("%lld %lld\n",i,G[i][j]);
//			}
//		}
		int ans=0;
		for(int i=1; i<=n; i++){
			bfs(i);
			for(int j=1; j<=n; j++){
				if(cnt[j]==2){
					A[min(i,j)][max(i,j)]=1;
//					printf("%lld %lld\n",i,j);
				}
//				printf("%lld ",dis[j]);
			} 
//			printf("\n");
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n;j++){
				if(A[i][j]){
					A[i][j]=0;
					ans++;	
				}
			}
		}
		printf("%lld\n",ans);
//		memset(A,0,sizeof(A));
		for(int i=1; i<=n; i++) G[i].clear();
	}
	return 0;
}
/*
0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
