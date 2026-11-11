#include<bits/stdc++.h>
#define int long long
#define N 510
#define M 500005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int n,m,d,w[M];

vector<int>a[N];
vector<int>b[M];
vector<int>t[M];
int dt[N][N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	int c,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			a[i].push_back(x);
			b[x].push_back(i);
			t[x].push_back(y);
		}
	}
	memset(dt,0x3f,sizeof dt);
	for(int i=0;i<=n;i++)dt[i][i]=0;
	for(int k=1;k<=m;k++){
		for(int i=0;i<(int)b[k].size();i++){
			for(int j=0;j<(int)b[k].size();j++){
				dt[b[k][i]][b[k][j]]=min(dt[b[k][i]][b[k][j]],t[k][i]+t[k][j]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dt[i][j]=min(dt[i][j],dt[i][k]+dt[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		if(x==y){cout<<0<<'\n';continue;}
		int ans=INF;
		for(int i=0;i<(int)b[x].size();i++){
			for(int j=0;j<(int)b[y].size();j++){
				ans=min(ans,t[x][i]+t[y][j]+dt[b[x][i]][b[y][j]]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
