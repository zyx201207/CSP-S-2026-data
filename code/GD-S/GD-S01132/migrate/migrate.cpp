#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c,t;
long long n,d;
long long x[N],dis[N],cnt[N];
bool vis[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		int tmp=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			if(i>1 && x[i]-x[i-1]>d) tmp++;
		}
		if(tmp==n-1){
			printf("0\n");
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			priority_queue<pair<int,int> > que;
			for(int j=1;j<=n;j++){
				dis[j]=2e18;
				cnt[j]=1;
			}
			dis[i]=0;
			que.push({0,i});
			while(!que.empty()){
				int dist=-que.top().first;
				int cur=que.top().second;
				que.pop();
				for(int k=1;k<=n;k++){
					if(k==cur||abs(x[k]-x[cur])>d) continue;
					if(dist+1==dis[k]) cnt[k]++;
					if(dist+1<dis[k]){
						dis[k]=dist+1;
						cnt[k]=1;
						que.push({-dis[k],k});
					}
				}
			}
			for(int p=i+1;p<=n;p++){
				if(cnt[p]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
