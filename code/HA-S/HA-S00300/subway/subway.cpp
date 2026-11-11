#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=500005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[M];
struct node{
	int x,t;
};
vector<node> vec[M];
ll f[N][N];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vec[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)vec[i].size();j++){
			node u=vec[i][j];
			for(int k=j+1;k<(int)vec[i].size();k++){
				node v=vec[i][k];
				f[u.x][v.x]=f[v.x][u.x]=min(f[u.x][v.x],u.t*1ll+v.t);
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ll res=INF;
		for(int j=0;j<(int)vec[x].size();j++){
			node u=vec[x][j];
			for(int k=0;k<(int)vec[y].size();k++){
				node v=vec[y][k];
				res=min(res,w[x]*1ll+w[y]*1ll+u.t*1ll+v.t+f[u.x][v.x]);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
