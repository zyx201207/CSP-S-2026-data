#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10,M=1e6+10;
int n,m,q,f[N][N];
int w[M];
struct aaa{
	int i,t;
};
vector<aaa> d[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e17;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int k,i=1;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			d[x].push_back({i,y});
		}
	}for(int i=1;i<=m;i++){
		for(int x=0;x<(int)d[i].size();x++){
			for(int y=0;y<(int)d[i].size();y++){
				f[d[i][x].i][d[i][y].i]=min(d[i][x].t+d[i][y].t,f[d[i][x].i][d[i][y].i]);
			}
		} 
	}for(int i=1;i<=n;i++){
		f[i][i]=0;
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e17,sum;
		for(int i=0;i<(int)d[x].size();i++){
			for(int j=0;j<(int)d[y].size();j++){
				sum=w[x]+w[y];
				sum+=d[x][i].t+d[y][j].t;
				sum+=f[d[x][i].i][d[y][j].i];
				ans=min(ans,sum);
			} 
		}cout<<ans<<"\n"; 
	}
}/*
100pts


*/
