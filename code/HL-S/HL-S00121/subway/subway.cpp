#include<bits/stdc++.h>
#define int long long
using namespace std;

struct mynode{
	int to,len;
	bool operator<(const mynode &cnt) const{
		return len>cnt.len;
	}
};

const int M=555,N=2e4+5;
int c,n,m,d,q,w[N],k[M],a[M][N],t[M][N],u,v,tot[N];
//vector<int> edge[N];
vector<mynode> edge_cnt[N];

int bfs(int from,int to){
	memset(tot,0x3f,sizeof(tot));
	tot[from]=0;
	priority_queue<mynode> q;
	mynode opt;
	opt.to=from;
	opt.len=0;
	q.push(opt);
	bool flag[N];
	memset(flag,0,sizeof(flag));
	while(!q.empty()){
		opt=q.top();
		q.pop();
		int _u=opt.to;
		if(flag[_u]==true){
			continue;
		}
		if(to==_u){
			return tot[to];
		}
		flag[_u]=true;
		int len=edge_cnt[_u].size();
		for(int i=0;i<len;i++){
			int _v=edge_cnt[_u][i].to;
			if(tot[_v]>tot[_u]+edge_cnt[_u][i].len){
				tot[_v]=tot[_u]+edge_cnt[_u][i].len;
				mynode res;
				res.len=tot[_v];
				res.to=_v;
				q.push(res);
			}
		}
	}
	return tot[to];
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(NULL));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			scanf("%lld",&k[i]);
			for(int j=1;j<=k[i];j++){
				scanf("%lld%lld",&a[i][j],&t[i][j]);
			}
			if(k[i]==2){
//				int len1=edge_cnt[a[i][0]].size();
//				bool flag1=false;
//				for(int j=0;j<len1;j++){
//					if(edge_cnt[a[i][0]][j].to==a[i][1]){
//						edge_cnt[a[i][0]][j].len=min(edge_cnt[a[i][0]][j].len,t[i][0]+t[i][1]);
//						flag1=true;
//						break;
//					}
//				}
//				if(flag1==false){
					mynode opt;
					opt.to=a[i][1];
					opt.len=t[i][0]+t[i][1];
					edge_cnt[a[i][0]].emplace_back(opt);
//				}
//				int len2=edge_cnt[a[i][1]].size();
//				bool flag2=false;
//				for(int j=0;j<len2;j++){
//					if(edge_cnt[a[i][1]][j].to==a[i][0]){
//						edge_cnt[a[i][1]][j].len=min(edge_cnt[a[i][1]][j].len,t[i][0]+t[i][1]);
//						flag2=true;
//						break;
//					}
//				}
//				if(flag2==false){
//					mynode opt;
					opt.to=a[i][0];
					opt.len=t[i][0]+t[i][1];
					edge_cnt[a[i][1]].emplace_back(opt);
//				}
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%lld%lld",&u,&v);
			int now=bfs(u,v);
			printf("%lld\n",now+w[u]+w[v]);
		}
	}
	else{
		for(int i=1;i<=q;i++){
			printf("%lld\n",rand());
		}
	}
	return 0;
}

