#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=5e5+10,N=505,D=25;
int T=0;
int c,n,m,d,q;
int w[M];
ll t[N][N];
vector<pair<int,int>> g[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >>m >>d >>q;
	for(int i=1;i<=m;i++) cin >>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >>k;
		for(int j=1;j<=k;j++){
			int a,tt;
			cin >>a >>tt;
			g[a].push_back({i,tt});
		}
	} 
	memset(t,0x3f,sizeof(t));
	for(int i=1;i<=m;i++) t[i][i]=0;
	ll INF=t[1][2];
	for(int i=1;i<=m;i++){
		for(auto[u,t1]:g[i]){
			for(auto[v,t2]:g[i]){
				if(u==v) continue;
				t[u][v]=min(t[u][v],ll(t1+t2));
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(t[k][i]>=INF) continue;
			for(int j=1;j<=n;j++){
				if(t[k][j]>=INF) continue;
				t[i][j]=min(t[i][j],t[k][i]+t[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin >>x >>y;
		ll mn=LLONG_MAX;
		for(auto[u,t1]:g[x]) for(auto[v,t2]:g[y]) mn=min(mn,t1+t[u][v]+t2);
		cout <<w[x]+mn+w[y] <<'\n';
	}
	return 0;
}
