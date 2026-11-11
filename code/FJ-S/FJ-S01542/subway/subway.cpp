//17:33 终于调出来了 哈哈哈哈哈哈哈啊哈哈哈
//17:38 样例7挂了吓死我了，发现是 INF 没调回 1e18，调完过了
//我成啦！！！！！ T3 T4 我来哩 
//17:42 加个快读 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
template<class T>
int binary(int l,int r,T cmp){
	while(l<r){
		int mid=l+(r-l)/2;
		cmp(mid)?l=mid+1:r=mid;
	}
	return l;
}
void chkmin(int&x,const int&y){
	(x>y)&&(x=y);
}
const int N=505,M=5e5+50;
int c,n,m,d,q;
int w[M],k[N];
struct inf{
	int a,t;
	friend bool operator<(inf x,inf y){
		return x.a<y.a;
	}
};
vector<inf>line[N];
vector<int>g[M],gt[M];
int eid[M*20],pid[M],idx,st[M*2],ed[M*2];
int f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
//	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
//		scanf("%lld",&k[i]);
		k[i]=read();
		line[i].resize(k[i]);
		for(int j=0;j<k[i];j++){
			line[i][j].a=read(),line[i][j].t=read();
//			scanf("%lld%lld",&line[i][j].a,&line[i][j].t);
			if(j==0)continue;
			eid[++idx]=i,pid[line[i][j].a]=i;
			st[idx]=line[i][j-1].a,ed[idx]=line[i][j].a;
			g[line[i][j].a].push_back(idx);
			gt[line[i][j].a].push_back(line[i][j].t);
			g[line[i][j-1].a].push_back(idx);
			gt[line[i][j-1].a].push_back(line[i][j-1].t);
		}
		sort(line[i].begin(),line[i].end());
//		cout<<"line"<<i<<'\n';
//		for(int j=0;j<k[i];j++){
//			cout<<line[i][j].a<<' '<<line[i][j].t<<'\n';
//		}
	}
	for(int i=1;i<=n;i++){
		fill(f[i]+1,f[i]+1+n,1e18);
	}
//	return 0;
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){//在i这个点换乘
		vector<int>ft(g[i].size()); 
		for(int p=0;p<(int)g[i].size();p++){
			int e=g[i][p],j=(st[e]==i?ed[e]:st[e]);
			ft[p]=line[eid[e]][binary(0,line[eid[e]].size(),[&](int x){
				return line[eid[e]][x].a<i;
			})].t;
//			printf("(%d)",j);
		}
//		cout<<"#"<<i<<'\n';
//		for(int p=0;p<g[i].size();p++){
//			printf("%lld ",ft[p]);
//		}
//		putchar('\n');
		for(int e1=0;e1<(int)g[i].size();e1++){
			for(int e2=e1+1;e2<(int)g[i].size();e2++){
				chkmin(f[eid[g[i][e1]]][eid[g[i][e2]]],ft[e1]+ft[e2]);
			}
		}
//		cout<<"FFF"<<i<<'\n';
	}
//	cout<<"OKK";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			chkmin(f[i][j],f[j][i]);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%10lld ",f[i][j]);
//		}
//		putchar('\n');
//	}
//	return 0;
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				chkmin(f[i][j],f[i][p]+f[p][j]);
			}
		}
	}
//	cout<<"Yes\n";
//	for(int i=1;i<=m;i++){
//		cout<<i<<":";
//		for(auto u:g[i]){
//			cout<<u<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int u=read(),v=read(),ans=1e18;
//		scanf("%lld%lld",&u,&v);
		for(int p1=0;p1<(int)g[u].size();p1++){
			int e1=g[u][p1];
			for(int p2=0;p2<(int)g[v].size();p2++){
				int e2=g[v][p2];
//				printf("%lld %lld\n",e1,e2);
				chkmin(ans,f[eid[e1]][eid[e2]]+gt[u][p1]+gt[v][p2]);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
