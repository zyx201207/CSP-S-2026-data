#include<bits/stdc++.h>
using namespace std;
int const MAXM=(int)5e5+5;
int const MAXN=505;
struct Node{
	int id;
	long long zhi;
	
	bool friend operator<(Node x,Node y){
		return x.zhi>y.zhi;
	}
};
int n,m,d,q;
int w[MAXM];
int a[MAXN][MAXN];
int t[MAXN][MAXN];
vector<int> v[MAXM];
long long dis[MAXN];
bool vis[MAXN];
int k[MAXN];
void djk(int kk){
	memset(dis,0x7f,sizeof(dis));
	priority_queue<Node> p;
	for(auto i : v[kk]){
		p.push({kk,w[i]+t[i][i]});
		dis[i]=w[i]+t[i][i];
	}
	while(!p.empty()){
		Node x=p.top();
		p.pop();
		vis[x.id]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(vis[a[i][j]]){
					continue;
				}
				vis[a[i][j]]=1;
				if(dis[a[i][j]]>dis[x.id]+t[i][j]+t[i][i]){
					dis[a[i][j]]=dis[x.id]+t[i][j]+t[i][i];
					p.push({a[i][j],dis[j]});
				}
				
				
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			v[a[i][j]].push_back(j);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		djk(x);
		printf("%lld\n",dis[y]+w[y]);
	}
	return 0;
}
