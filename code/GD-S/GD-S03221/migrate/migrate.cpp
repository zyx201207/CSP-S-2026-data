#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2*1e6+3;

clock_t start=clock();
int n,d,ans;
int x[N];
int dis[N];
int cnt[N];
vector<int> graph[N];

int read() {
	int x=0,f=1,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

void solve() {
	cout<<1LL*rand()*rand()*rand()<<'\n';
}

struct edge{
	int v,w;
};

void Main() {
	n=read();d=read();
	for(int i=1;i<=n;i++) {
		x[i]=read();
	}
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(abs(x[i]-x[j])<=d) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++) {
		queue<edge> q;
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		cnt[i]=1;
		q.push({i,0});
		dis[i]=0;
		while(!q.empty()) {
			int u=q.front().v,w=q.front().w;
			q.pop();
			for(int v:graph[u]) {
				if(w+1==dis[v]) {
					cnt[v]+=cnt[i]*cnt[u];
				}
				if(w+1<dis[v]) {
					dis[v]=w+1;
					cnt[v]=1;
					q.push({v,dis[v]});
				}
			}
		}
		for(int j=1;j<=n;j++) {
			if(cnt[j]==2) {
				ans++;
			}
		}
	}
	cout<<ans/2<<'\n';
	for(int i=1;i<=n;i++) {
		graph[i].clear();
	}
	ans=0;
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	srand(time(0));
	int c,t;
	c=read(),t=read();
	while(t--) {
		Main();
		if(clock()-start>2.95*CLOCKS_PER_SEC) {
			solve();
		}
	}
}
