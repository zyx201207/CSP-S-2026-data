#include <bits/stdc++.h>
#define int long long
#define F(i,l,r) for(int i=l;i<=r;i++)
#define E(i,r,l) for(int i=r;i>=l;i--)
#define Luogu return
#define _DEQUE_ 0
using namespace std;

const int N=1e6+5,inf=1e18,M=2e3+5;

void fre(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}

int n,m,c,d,q,w[N];

vector<pair<int,int> >e[N];

int f[M][M];

void add(int u,int v,int t){
	e[u].push_back({v,t});
	f[u][v]=t;
	f[v][u]=t;
}

void floyd(){
	F(i,1,m)f[i][i]=0;
	F(k,1,m){
		F(i,1,m){
			F(j,1,m){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fre();
	cin>>c>>n>>m>>d>>q;
	F(i,1,n+m){
		F(j,1,n+m){
			f[i][j]=inf;
		} 
	}
	F(i,1,m)cin>>w[i];
	F(i,1,n){
		int k;
		cin>>k;
		if(c>=7&&c<=11){
			int x,t1,y,t2;
			cin>>x>>t1>>y>>t2;
			f[x][y]=min(f[x][y],t1+t2);
			f[y][x]=min(f[y][x],t1+t2);
			continue;
		}
		F(j,1,k){
			int x,t;
			cin>>x>>t;
			add(m+i,x,t);
			add(x,m+i,t);
		}
	}
	if(c<=6){
		m+=n;
		floyd();
		F(i,1,q){
//			cout<<i<<endl;
			int x,y;
			cin>>x>>y;
			cout<<f[x][y]+w[x]+w[y]<<endl;
		}
	}else if(c<=11){
		floyd();
		F(i,1,q){
			int x,y;
			cin>>x>>y;
			cout<<f[x][y]+w[x]+w[y]<<endl;
		}
	}



	Luogu _DEQUE_;
}

