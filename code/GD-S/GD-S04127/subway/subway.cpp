#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int id,t;
};
int c,n,m,d,q,w[500005],k[505];
vector<node> has[500005];
int f[505][505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			has[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)	f[i][i]=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int len=has[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int u=has[i][j].id,v=has[i][k].id;
				f[u][v]=f[v][u]=min(f[u][v],has[i][j].t+has[i][k].t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				cnt++;
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		int ans=1e18;
		int lenx=has[x].size(),leny=has[y].size();
		for(int j=0;j<lenx;j++){
			for(int k=0;k<leny;k++){
				int u=has[x][j].id,v=has[y][k].id;
				ans=min(ans,f[u][v]+has[x][j].t+has[y][k].t);
			}
		}
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}
