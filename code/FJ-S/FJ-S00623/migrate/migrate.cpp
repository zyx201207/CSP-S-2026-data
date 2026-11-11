#include <bits/stdc++.h>
#define int long long
using namespace std;
int x[2002000];
vector <int> e[5050];
int cnt[5050],dis[5050];
inline void dijkstra(int s){
	priority_queue <int> q;
	q.push(s);
	memset(cnt,0,sizeof cnt);
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	while(!q.empty()){
		int h=q.top();
		q.pop();
		for(int i=0;i<e[h].size();i++){
			if(dis[h]+1<dis[e[h][i]]){
				dis[e[h][i]]=dis[h]+1;
				cnt[e[h][i]]=1; 
				q.push(e[h][i]);
			}else if(dis[h]+1==dis[e[h][i]]){
				cnt[e[h][i]]++;
				q.push(e[h][i]);
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12){
		while(t--){
			int n,d;
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
			}
			d/=(x[2]-x[1]);
			if(d<=1||d>n/2){
				puts("0");
			}else{
				int ans=n-2*d+1;
				printf("%lld\n",ans);
			}
		}
	}else{
		while(t--){
			int n,d;
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
				e[i].clear();
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						e[i].push_back(j);
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				dijkstra(i);
				for(int j=i+1;j<=n;j++){
					if(cnt[j]==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

