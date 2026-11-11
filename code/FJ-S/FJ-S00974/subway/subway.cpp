#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int w[N],deg[N];
ll f[510][510];
vector<int> id[N],g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(f,0x3f,sizeof(f));
	for(int i=1,k;i<=n;i++){
		f[i][i]=0;
		cin>>k;
		for(int j=1,x,v;j<=k;j++){
			cin>>x>>v;
			id[x].push_back(i);
			g[x].push_back(v);
			deg[x]++;
		}
	}
	for(int x=1;x<=m;x++){
		for(int i=0;i<deg[x];i++){
			for(int j=i+1;j<deg[x];j++){
				ll vl=g[x][i]+g[x][j],y=id[x][i],z=id[x][j];
				f[y][z]=f[z][y]=min(f[y][z],vl);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=0;i<deg[x];i++){
			for(int j=0;j<deg[y];j++)ans=min(ans,f[id[x][i]][id[y][j]]+g[x][i]+g[y][j]);
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
//14:58 通过大样例，最后一个 0.6s，不知道能不能过。
//好像没开满，没事不影响，相信 CCF 少爷机。 
