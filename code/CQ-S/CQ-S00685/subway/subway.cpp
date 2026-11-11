#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cerr<<#x<<':'<<x<<endl
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e2+5,M=5e5+5,inf=1e18;
int c,n,m,d,q;
int w[M];
int f[N][N];
struct node{
	int x,w;
};
vector<node> p[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IOS; 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,a,t;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			p[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(auto u:p[i]){
			for(auto v:p[i]){
				f[u.x][v.x]=min(f[u.x][v.x],u.w+v.w);
				f[v.x][u.x]=min(f[v.x][u.x],u.w+v.w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int _=1,x,y;_<=q;_++){
		cin>>x>>y;
		int ans=inf;
		for(auto u:p[x]){
			for(auto v:p[y]){
				ans=min(ans,f[u.x][v.x]+u.w+v.w);
				if(u.x==v.x) ans=min(ans,u.w+v.w);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

