#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;

const int N=505,M=5e5+5;

int GUNMU,n,m,d,T;
int a[M],len[M];
int dis[N][N];

struct node{
	int ds,id;
}sw[22][M];

vector<int> adj[N];

inline int distance(int s,int t){
	int ans=0x7f7f7f7f7f7f7f7fll;
	for(int i=1;i<=len[s];++i){
		for(int j=1;j<=len[t];++j){
			ans=min(ans,dis[i][j]+sw[j][t].ds);
		}
	}
	return ans;
}

signed main(){
	freopen("subway1.in","r",stdin);
	//freopen("sample.out","w",stdout);
	fast;
	cin>>GUNMU>>n>>m>>d>>T;
	for(int i=1;i<=m;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int to,ds;
			cin>>to>>ds;
			sw[++len[to]][to]={ds,i};
			adj[i].push_back(to);
		}
	}//cerr<<"input success\n";
	memset(dis,0x7f,sizeof dis);
	for(int i=1;i<=n;++i) dis[i][i]=0;
	for(int i=1;i<=n;++i){
		for(int j:adj[i]){
			for(int k=1;k<=len[j];++k)
			dis[i][sw[k][j].id]=min(dis[i][sw[k][j].id],a[j]);
		}
	}//cerr<<"init success\n";
	for(int mid=1;mid<=n;++mid){
		for(int i=1;i<=n;++i){
			if(dis[i][mid]!=0x7f7f7f7f7f7f7f7fll)
				for(int j=1;j<=n;++j){
					dis[i][j]=min(dis[i][j],dis[i][mid]+dis[mid][j]);
				}
		}
	}//cerr<<"floyd success\n";
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			cerr<<dis[i][j]<<' ';
		cerr<<'\n';
	}
	while(T--){
		int s,t;
		cin>>s>>t;
		cout<<a[s]+a[t]+distance(s,t)<<'\n';
	}//cerr<<"qry seccess\n";
	return 0;
}

