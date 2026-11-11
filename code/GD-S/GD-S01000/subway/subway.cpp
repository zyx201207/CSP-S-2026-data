#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
const int MAXM = 5*1e5+5;
const int MAXN = 505;
struct Node {
	int road,ti,xu;
};
struct FAME{
	int ai,ti;
};
int w[MAXM];
long long dis[MAXN];
bool f[MAXN];
vector<FAME> lu[MAXM];//daolu
vector<Node> v[MAXN];//地铁站 
int c,n,m,d,q;

void bfs(int u,int ve){
	queue<int> q;
	q.push(u);
	memset(f,0,sizeof(f));
	memset(dis,0,sizeof(dis));
	f[u]=true;
	while(!q.empty()){
		int fe=q.front();
		q.pop(); 
		for(int i=0;i<v[fe].size();i++){
			Node te=v[fe][i];
			int to,wd;
			if(te.xu-1>0){
				to=lu[te.road][te.xu-1].ai;
				wd=te.xu-1;
			}else{
				to=lu[te.road][te.xu+1].ai;
				wd=te.xu+1;
			}
			if(to==true)continue;
			f[to]=true;
			dis[to]=dis[fe]+lu[te.road][te.xu].ti+lu[te.road][wd].ti;
			if(to==ve){
				dis[ve]+=w[u]+w[ve];
				cout<<dis[ve]<<'\n';
				return;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	//记得删除批注！！！删除其余文件！！！ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki,p,q;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			cin>>p>>q;
			v[p].push_back({i,q,j-1});
			lu[i].push_back({p,q});
		}
	}
	for(int i=1;i<=q;i++){
		int u,ve;
		long long ans=0;
		cin>>u>>ve;
		ans+=w[u]+w[ve];
		if(c>=7&&c<=11){
			bfs(u,ve);
		}
	}
	
	
	return 0;
} 
