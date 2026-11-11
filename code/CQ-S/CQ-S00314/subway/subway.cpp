#include<bits/stdc++.h>
#define wef(i,l,r) for(int i=l;i<=r;i++)
#define few(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define endl cout<<"\n"
using namespace std;
using ll=long long;
const int N=505,M=5e5+5;
ll d[N][N],W[M];
vector<pii> g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);int CCCCC;cin>>CCCCC;
	
	int n,m,D,Q;
	cin>>n>>m>>D>>Q;
	wef(i,1,m) cin>>W[i];
	wef(i,1,n){
		int k;
		cin>>k;
		wef(j,1,k){
			int x,w;
			cin>>x>>w;
			g[x].emplace_back(i,w);
		}
	}
	
	memset(d,0x3f,sizeof d);
	wef(i,1,n) d[i][i]=0;
	wef(i,1,m){
		int nn=g[i].size();
//		cout<<nn<<"\n";
		wef(j,0,nn-1) wef(k,j+1,nn-1){
			int x=g[i][j].first,y=g[i][k].first;
			d[x][y]=(ll)g[i][j].second+g[i][k].second;
			d[y][x]=(ll)g[i][j].second+g[i][k].second;
		}
	}
	
	wef(t,1,n) wef(i,1,n) wef(j,1,n){
		d[i][j]=min(d[i][j],d[i][t]+d[t][j]);
	}
//	wef(i,1,n){
//		wef(j,1,n) cout<<d[i][j]<<" ";
//		endl;
//	}
	
	while(Q--){
		int x,y;
		cin>>x>>y;
		int nn=g[x].size(),mm=g[y].size();
		ll res=0x3f3f3f3f3f3f3f3f;
		wef(i,0,nn-1){
			wef(j,0,mm-1){
				int u=g[x][i].first,v=g[y][j].first;
				res=min(res,g[x][i].second+g[y][j].second+d[u][v]);
			}
		}
		cout<<res+W[x]+W[y]<<"\n";
	} 
	return 0;
}

