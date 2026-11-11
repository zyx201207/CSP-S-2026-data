#include<iostream>
#include<vector>
using namespace std;


const int maxn=1e5+10;
struct NODE{
	int bq,node;
};
bool cmp(NODE bb,NODE b){
	return bb.bq<b.bq;
}
vector<vector<NODE > > G;
int c,n,m,d,q;
int w[maxn];
int k[maxn],a[510][maxn],t[510][maxn];
int x[maxn],y[maxn];
int v[510][maxn],s[21],e[21],ss=1,ee=1,dp_max,vis[maxn];
bool f=false;


void add(int u,int u_bq,int v,int v_bq){
	NODE E;
	E.bq=u_bq+v_bq;
	E.node=u;
	G[v].push_back(E);
	E.node=v;
	G[u].push_back(E);
}
void dfs(int dp,int Nn,int W){
	if(f){
		return;
	}
	if(Nn==e[ee]){
		printf("%d\n",W);
		f=true;
		return;
	}
	if(dp>dp_max){
		return;
	} 
	for(int i=0;i<G[Nn].size();i++){
		if(!vis[G[Nn][i].node]){
			vis[G[Nn][i].node]=1;
			dfs(dp+1,G[Nn][i].node,W+G[Nn][i].bq);
			vis[G[Nn][i].node]=0;
		}
	}
}
int main(){
	
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(v[i][j]>=1){
				a[i][j]+=m;
			}
			v[i][j]++;
			if(j>1){
				add(a[i][j-1],0,a[i][j],0);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	
	
	for(int i=1;i<=m*d;i++){
		vector<NODE > lu;
		G.push_back(lu);
	}
	for(int i=1;i<n;i++){
		for(int ii=1;ii<=k[i];ii++){
			for(int j=i+1;j<=n;j++){
				for(int jj=1;jj<=k[j];jj++){
					if(a[i][ii]%m==a[j][jj]%m){
						add(a[i][ii],t[i][ii],a[j][jj],t[j][jj]);
					}
				}
			}
		}
	}
	
	
	int sum=0;
	while(G[sum+1].size()!=0){
		sum++;
	}
	for(int i=1;i<=q;i++){
	int s_cnt=1,e_cnt=1;
		int T=0;
		while(T*m+x[i]<=sum){
			s[s_cnt]=T*m+x[i];
			s_cnt++;
		}
		T=0;
		while(T*m+y[i]<=sum){
			e[e_cnt]=T*m+y[i];
			e_cnt++;
		}
		for(int ss=1;ss<=s_cnt;ss++){
			for(int ee=1;ee<=e_cnt;ee++){
				int W=0;
				for(int i=1;i<=k[s[ss]/m+1];i++){
					if(a[s[ss]/m+1][i]==s[ss]){
						W+=w[s[ss]]+t[s[ss]/m+1][i];
					}
				}
				for(int i=1;i<=k[e[ee]/m+1];i++){
					if(a[e[ee]/m+1][i]==e[ee]){
						W+=w[e[ee]]+t[e[ee]/m+1][i];
					}
				}
				for(int i=1;i<=sum;i++){
					vis[i]=0;
				}
				for(dp_max=1;dp_max<=sum;dp_max++){
					if(f){
						break;
					}
					dfs(1,s[ss],W);
				}
			}
		}
	}
	return 0;
}
