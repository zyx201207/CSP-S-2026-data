#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long a[500005];
vector<pair<long long,long long> >x3[500005];
vector<pair<long long,long long> >x[500005];
vector<pair<long long,long long> >x2[505];
long long c,n,m,d,q;
long long h[500005];
long long tt=0;
void dfs(long long u,long long v,long long c){
	if(h[u]<=c)return;
	h[u]=c;
	int f=x3[u].size();
	for(int i=0;i<f;i++){
		dfs(x3[u][i].first,v,c+x3[u][i].second);
	}
}
int wq[500005][2];
bool vis[500005];
int vis2[505];
int bfs(int u,int v){
	int h=1000000;
	wq[1][0]=u;
	wq[1][1]=0;
	vis[u]=1;
	int head=0,tail=1;
	while(head<=tail){
		head++;
		int xe=wq[head][0];
		int len=x[xe].size();
		for(int i=0;i<len;i++){
			int ye=x[xe][i].first;
			if(vis2[ye]>ye){
				vis2[ye]=ye;
				int len2=x2[ye].size();
				for(int j=0;j<len2;j++){
					int ze=x2[ye][j].first;
					if(vis[ze]==0){
						vis[ze]=1;
						if(ze==v){
							h=min(h,wq[head][1]+1);
						}
						tail++;
						wq[tail][0]=ze;
						wq[tail][1]=wq[head][1]+1;
					}
				}
			}
		}
	}
	return h;
}
void op(int u,int v){
	long long ans=a[u]+a[v];
	for(int i=1;i<=m;i++){
		h[i]=1000000000000000;
	}
	dfs(u,v,0);
	cout<<ans+h[v]<<'\n';
}
void opp(int u,int v){
	long long ans=a[u]+a[v];
	for(int i=1;i<=m;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		vis2[i]=10000;
	}
	cout<<ans+tt*bfs(u,v)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int maxc=0;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		maxc=max(maxc,k);
		for(int j=1;j<=k;j++){
			long long v,t,u,r;
			cin>>v>>t;
			x[v].push_back(make_pair(i,t));
			x2[i].push_back(make_pair(v,t));
			tt=t;
			if(k==2&&j==1){
				x3[v].push_back(make_pair(0,t));
				u=v;
				r=t;
			}
			if(k==2&&j==2){
				int len=x3[u].size();
				x3[u][len-1].first=v;
				x3[u][len-1].second+=t;
				x3[v].push_back(make_pair(u,t));
				int len2=x3[v].size();
				x3[v][len2-1].first=u;
				x3[v][len2-1].second+=r;
			}
		}
	}
	tt*=2;
	if(maxc==2){
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			op(u,v);
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		opp(u,v);
	}
	return 0;
}
