#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+6;
int c,t;
int n,d;
int x[N];
vector<int>E[N];

int ans;

int dist[7007][7007];
int cnt[7007][7007];
bool vis[10005];

void bfs(int st) {
	queue<int>q;
	dist[st][st]=0;
	cnt[st][st]=1;
	q.push(st);
	
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		
//		if(vis[u]) {
//			continue;
//		}
//		vis[u]=true;
		
		for(int v : E[u]) {
			if(dist[st][u]+1==dist[st][v]) {
				cnt[st][v]++;
				q.push(v);
			}
			if(dist[st][u]+1<dist[st][v]) {
				dist[st][v]=dist[st][u]+1;
				cnt[st][v]=1;
				q.push(v);
			}
		}
	}
	return ;
}

bool pd() {
	for(int i=3;i<=n;i++) {
		if(x[i]-x[i-1]!=x[i-1]-x[i-2]) {
			return false;
		}
	}
	return true;
}

bool pd1() {
	for(int i=1;i<=n;i++) {
		if(d>=x[i]-x[1] && d>=x[n]-x[i]) {
			continue;
		}
		return false;
	}
	return true;
}
signed main() {
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	scanf("%lld%lld",&c,&t);
	
	while(t--) {
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) {
			scanf("%lld",&x[i]);
			E[i].clear();
		}
		
		if(n<=7000) {
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					dist[i][j]=INT_MAX;
					cnt[i][j]=0;
				}
			}
			
			for(int i=1;i<=n;i++) {
				for(int j=i+1;j<=n;j++) {
					if(i==j) {
						continue;
					}
					if(abs(x[i]-x[j])<=d) {
						E[i].push_back(j);
						E[j].push_back(i);
					}
				}
			}
			
			ans=0;
			
			for(int i=1;i<=n;i++) {
				bfs(i);
			}
			
			for(int i=1;i<=n;i++) {
				for(int j=i+1;j<=n;j++) {
					ans+=(cnt[i][j]==2);
				}
			}
			
			printf("%lld\n",ans);
		}
		
		else if(pd()) {
			int k=2*(d/(x[2]-x[1]))-1;
			if(d<x[2]-x[1] || k==1) {
				printf("0\n");
			}
			else {
				printf("%lld\n",max(0ll,n-k));
			}
		}
		
		else if(pd1()) {
			printf("0\n");
		}
	}
	return 0;
}
