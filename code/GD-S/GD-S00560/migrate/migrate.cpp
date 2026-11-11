#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],s[2000005];
int dis[5005][5005],cnt[5005][5005];

void bfs(int st){
	queue<int> q;
	for(int i = st;i <= n;++i)
		dis[st][i] = 1e10;
	dis[st][st] = 0,cnt[st][st] = 1;
	q.push(st); 
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(int i = now + 1;i <= n;++i)
			if(abs(a[i] - a[now]) <= d){
				if(dis[st][i] > dis[st][now] + 1)
					dis[st][i] = dis[st][now] + 1,cnt[st][i] = cnt[st][now],q.push(i);
				else if(dis[st][i] == dis[st][now] + 1)
					cnt[st][i]++;
			}
			else break;
	}
	return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	for(int _ = 1;_ <= t;++_){
		scanf("%lld %lld",&n,&d);
		for(int i = 1;i <= n;++i)
			scanf("%lld",&a[i]);
		if(n <= 5005){
			int ans = 0;
			for(int i = 1;i <= n;++i)
				bfs(i);
			for(int i = 1;i <= n;++i){
				for(int j = i + 1;j <= n;++j){
//					printf("(%lld,%lld) , ",dis[i][j],cnt[i][j]);
					if(cnt[i][j] == 2)
						ans++;
					cnt[i][j] = 0;
				}
//				printf("\n");
			}
			printf("%lld\n",ans);
		}
		else{
			int k = a[2] - a[1];
			if(d <= k) printf("0\n");
			else printf("%lld\n",n - d / k - 1);
		}
	}
	return 0;
}

