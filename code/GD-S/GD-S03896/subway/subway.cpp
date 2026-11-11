#include<bits/stdc++.h>
using namespace std;
const long long maxm=3000005;
const long long maxn=4000005;
const long long INF=1e18;
int head[maxm];
int to[maxm*2];
int nxt[maxm*2];
long long wt[maxm*2];
int usd[maxm],usc=0;
long long dist[maxn];

void ade(int u,int v,long long w){
	to[++usc]=v;wt[usc]=w;nxt[usc]=head[u];head[u]=usc;
	to[++usc]=u;wt[usc]=w;nxt[usc]=head[v];head[v]=usc;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;
	if(!(cin>>c>>n>>m>>d>>q))return 0;
	memset(head,-1,sizeof(head));
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;++i){
		long long w;
		cin>>w;
		ade(i,m+i,w);	
	}
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		int ln=2*m+i;
		for(int j=1;j<=k;++j){
			int a;
			long long t;
			cin>>a>>t;
			ade(m+a,ln,t);
		}
	}
	while(q--){
		int st,tar;
		cin>>st>>tar;
		usc=0;
		dist[st]=0;
		usd[++usc]=st;
		priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>>pq;
		pq.push({0,st});
		while(!pq.empty()){
			auto [d,u]=pq.top();
			pq.pop();
			if(d>dist[u])continue;
			if(u==tar)break;
			for(int e=head[u];e!=-1;e=nxt[e]){
				int v=to[e];
				if(dist[v]>d+wt[e]){
					if(dist[v]=0x3f3f3f3f3f3f3f3fLL){
						usd[++usc]=v;
					}
					dist[v]=d+wt[e];
					pq.push({dist[v],v});
				}
			}
		}
		cout<<dist[tar]<<endl;
		for(int i=1;i<=usc;++i){
			dist[usd[i]]=0x3f3f3f3f3f3f3f3fLL;
		}
	}
	return 0;
} 
