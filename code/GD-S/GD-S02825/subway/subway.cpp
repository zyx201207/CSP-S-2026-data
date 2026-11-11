#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
ll w[M],f[N][N];
vector<pair<int,ll>>e[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a;j<=k;j++){
			ll t;
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			f[i][j]=(ll)(1e18);
		}
	}
	for(int now=1;now<=m;now++){
		for(int i=0;i<(int)e[now].size();i++){
			for(int j=i+1;j<(int)e[now].size();j++){
				int u=e[now][i].first,v=e[now][j].first;
				ll u_t=e[now][i].second,v_t=e[now][j].second;
				f[u][v]=min(f[u][v],u_t+v_t);
				f[v][u]=min(f[v][u],v_t+u_t);
			}
		}
	}
	for(int mid=1;mid<=n;mid++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][mid]+f[mid][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll mn=(ll)(1e18);
		for(int i=0;i<(int)e[x].size();i++){
			for(int j=0;j<(int)e[y].size();j++){
				int u=e[x][i].first,v=e[y][j].first;
				ll u_t=e[x][i].second,v_t=e[y][j].second;
				mn=min(mn,w[x]+u_t+f[u][v]+v_t+w[y]);
			}
		}
		cout<<mn<<'\n';
	}
	return 0;
}
