#include <bits/stdc++.h>

#define int ll
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back
#define endl "\n"

using namespace std;

const int inf=1e18;

const int MAXK=500000;
vector<pr>k[MAXK+5];
int w[MAXK+5];

const int MAXN=500;
int vl[505][505];

int ans[505][505];

int c,n,m,d,q;

struct node{
	int s,b;
	bool friend operator <(node q,node p){
		return q.s>p.s; 
	}
};

struct nodes{int l,s;};
vector<nodes>bs[505];

priority_queue<node>qq;
bitset<505>vis;

void dij(int sta){
	ans[sta][sta]=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	qq.push((node){0ll,sta});
	while(!qq.empty()){
		node mq=qq.top();
		qq.pop();
		if(vis[mq.b]==1) continue;
		vis[mq.b]=1;
		for(nodes ne:bs[mq.b]){
			int i=ne.l,val=ne.s;
			if(vis[i]==false&&ans[sta][i]>ans[sta][mq.b]+val){
				ans[sta][i]=ans[sta][mq.b]+val;
				qq.push((node){ans[sta][mq.b]+val,i});
			} 
		} 
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int ks;scanf("%lld",&ks);
		for(int j=1;j<=ks;j++){
			int a,b;
			scanf("%lld%lld",&a,&b);
			k[a].pb(mp(i,b));
		}
	}
	
	for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++) {ans[i][j]=vl[i][j]=inf;} ans[i][i]=vl[i][i]=0;}
	for(int i=1;i<=m;i++){
		for(int j=0;j<k[i].size();j++){
			for(int kk=j+1;kk<k[i].size();kk++){
				vl[k[i][j].first][k[i][kk].first]=min(vl[k[i][j].first][k[i][kk].first],k[i][j].second+k[i][kk].second);
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {bs[i].pb((nodes){j,vl[i][j]});bs[j].pb((nodes){i,vl[i][j]});}
	for(int i=1;i<=n;i++){ans[i][i]=0;dij(i);}
	while(q--){
		int a,b;scanf("%lld%lld",&a,&b);
		int da=inf;
		for(int i=0;i<k[a].size();i++){
			for(int j=0;j<k[b].size();j++){
				da=min(da,w[a]+w[b]+k[a][i].second+k[b][j].second+ans[k[a][i].first][k[b][j].first]);
			}
		}
		printf("%lld\n",da);
	}
	return 0;
}

