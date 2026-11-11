#include<bits/stdc++.h>
using namespace std;
const int N=5e4+1001;
const int M=505;
int p[N][M];//N条线路第M个站点是多少 
int w[M];//地铁到站厅
int t[M][N];//站厅到站台
int w1[M][M];//站内换台费用 
//int w2[M][N];//从地铁口到站台 
int ans[M][M];//两点间的最短距离 
int c,n,m,d,q;
struct node{
	int pos,w,l;//站点，花费,当前所处线路 
};
bool v[M];
int nw[M];//到达每个点的最优值 
void f(int x,int y){
	memset(v,0,sizeof(0));
	memset(nw,127,sizeof(nw));
	queue<node>q;
	//先上车; 		
	for(int i=1;i<=N;++i){
		if(!t[x][i])continue;
		for(int j=1;j<=M;++j){
			if(p[i][j]==x)continue;
			if(p[i][j])q.push({p[i][j],t[x][i]+w[x],i});
			else break;
		}
	}
	while(!q.empty()){
		node n1=q.front();q.pop();
		int u=n1.pos;
		int ws=n1.w;
		int l=n1.l;
		//if(v[u])continue;
		//v[u]=1;
		for(int i=1;i<=N;++i){//选择换乘 
			if(!t[u][i])continue;
			for(int j=1;j<=M;++j){
				int wd=ws+t[u][l]+t[u][i];
				int np=p[i][j];
				if(wd>=nw[np])continue;
				if(np==y){
					ans[x][y]=min(ans[x][y],wd+t[y][i]+w[y]);
				}
				if(np&&np!=u)q.push({p[i][j],wd,i});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	int k=0;
	for(int i=1,a,tmp;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>tmp;
			p[i][j]=a;
			t[a][i]=tmp;			
		}
	}
	for(int i=0,x,y;i<q;++i){
		cin>>x>>y;
		f(x,y);
		cout<<ans[x][y]<<endl;
	}
	return 0;
}
