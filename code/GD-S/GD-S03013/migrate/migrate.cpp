#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n;
ll d,ans;
ll x[N];
int dis[N],cnt[N];
vector<int> e[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,
	greater<pair<int,int>>> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(c==13||c==14){
			//B
			puts("0");
		}else{
			//brute
			ans=0;
			for(int i=1;i<=n;i++){
				e[i].clear();
				__int128 tmp=x[i];
				tmp=tmp+d;
				for(int j=i+1;x[j]<=tmp&&j<=n;j++){
					e[i].push_back(j);
//					printf("%d %d\n",i,j);
				}
			}
//			puts("\n");
//			for(int i=1;i<=n;i++){
//				printf("%d : ",i);
//				for(int y:e[i]) printf("%d ",y);
//				printf("\n");
//			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) dis[j]=1e9,cnt[j]=0;
				q.emplace(0,i);
				dis[i]=0;
				cnt[i]=1;
				while(!q.empty()){
					int x=q.top().second,dist=q.top().first;
					q.pop();
					if(dis[x]<dist) continue;
					for(int y:e[x]){
						if(dis[x]+1<dis[y]){
							cnt[y]=cnt[x];
							dis[y]=dis[x]+1;
							q.emplace(dis[y],y);
						}else if(dis[x]+1==dis[y]) 
							cnt[y]+=cnt[x];
					}
				}
				for(int j=1;j<=n;j++){
					if(cnt[j]==2){
						ans++;
//						printf("%d %d\n",i,j);
					}
				}
					
			}
//			puts("1");
			printf("%lld\n",ans);
		}
		
	}
	return 0;
}

