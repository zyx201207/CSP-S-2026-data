#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize(2) 
#define int long long 
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define pii pair<int,int>
#define x first 
#define y second
const int N=510,M=5e5+10,inf=1e16;
vector<pii> e[N];//xianlu zhong de 	
vector<pii> g[M];
int c,n,m,d,q,w[M];
int f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m) cin>>w[i];
	rep(i,1,n){
		int k;
		cin>>k;
		rep(j,1,k){
			int x,y;
			cin>>x>>y;
			g[x].push_back({i,y});
		}
	}
	memset(f,0,sizeof(f));
	rep(i,1,m){
		for(int j=0;j<g[i].size();++j){
			for(int k=j+1;k<g[i].size();++k){
				int a=g[i][j].x,b=g[i][k].x,ww=g[i][j].y+g[i][k].y;
				f[a][b]=f[b][a]=ww;
			} 
		}
	}
	rep(i,1,n) rep(j,1,n){
		if(i==j) f[i][j]=0;
		else{
			if(f[i][j]==0) f[i][j]=inf;
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,i+1,n){
				int t=min(f[i][j],f[i][k]+f[k][j]);
				f[i][j]=f[j][i]=min(f[i][j],t);
			}
		}
	}
//	cout<<f[1][2]<<"\n";
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(pii i:g[x]) for(pii j:g[y]){
			ans=min(ans,f[i.x][j.x]+i.y+j.y);
		} 
//		cout<<w[x]+w[y]<<" ";
		cout<<ans+w[x]+w[y]<<"\n";
	}
//	rep(i,1,n) rep(j,i+1,n) if(f[i][j]!=0) e[i].push_back({j,f[i][j]}),
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

ans:
32
17



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
ans:
35
16
*/
