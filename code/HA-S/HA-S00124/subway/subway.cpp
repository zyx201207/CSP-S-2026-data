#include<bits/stdc++.h>
using namespace std;

const int M = 1005;
const int N = 505;

bool e[M][N][N];

int c,n,m,d,Q,w[M],ans,sum[N][N],size[N],qp[M][N];//w地铁口到站厅 ,n条铁路，m条站点 

int a[N][M];//铁路x站点，站厅到站台t秒 
//站口-->站厅-->站台 

bool vis[N][M];

queue<pair<int,int> > q;
void init(int uu)
{
	sum[uu][uu]=a[uu][uu];
	for(int i = 1;i <= n;i++){
		if(vis[i][1]) q.push({i,1});
	}
	while(!q.empty()){
		int u = q.front().second,l=q.front().first;
		q.pop();
		for(int i = 1;i <= qp[l][u];i++){
			int v = e[l][u][i];
			q.push({l,v});
			sum[u][v]=min(sum[u][v],a[l][u]+a[l][v]);
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	memset(sum,1e9,sizeof sum);
	cin >>c >>n >>m >>d >>Q;
	for(int i = 1;i <=m;i++){
		cin >>w[i];
	}
	for(int i = 1;i <= n;i++){
		int kkk;
		cin >>kkk;
		int x1,y1,x2,y2;
		cin >>x1 >>y1;
		bool f=0;
		for(int j = 2;j <= kkk;j++){
			if(!f){
				f=1;
				cin >> x2 >>y2;
				e[i][x1][x2]=1;
				a[i][x2]=y2;
				qp[i][x1]++;
				vis[i][x2]=1;
			}else{
				f=0;
				cin >> x1 >>y1;
				e[i][x2][x1]=1;
				a[i][x1]=y1;
				qp[i][x2]++;
				vis[i][x1]=1;
			}
			size[i]++;
		}
	}
	init(1);
	while(Q--){
		int l,r;
		cin >> l >>r;
		ans=0;
		ans+=w[l]+w[r];
		ans+=sum[l][r];
		cout <<ans <<"\n";
	}
	return 0;
}

