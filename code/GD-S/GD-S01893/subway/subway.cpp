#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define l first
#define r second
using namespace std;
const int maxn=5e5+5;
int n,m,d,q,a[maxn],len,x,val,l[maxn],r[maxn],ans[maxn],dis[maxn],vis[maxn],tot,dist[505][505],L,R;
vector<pii> v[maxn],g[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int C;
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>x>>val;
			v[x].push_back({i,val});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dist[i][j]=0;
			else dist[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=j+1;k<v[i].size();k++){
				dist[v[i][j].l][v[i][k].l]=dist[v[i][k].l][v[i][j].l]=v[i][j].r+v[i][k].r;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>L>>R;
		int ans=1e18;
		for(int j=0;j<v[L].size();j++){
			for(int k=0;k<v[R].size();k++){
				ans=min(ans,dist[v[L][j].l][v[R][k].l]+v[L][j].r+v[R][k].r);
			}
		}
		cout<<ans+a[L]+a[R]<<"\n";
	}
	return 0;
} 
