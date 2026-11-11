#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
ll n,m,d,q;
ll a[M];
struct node{
	ll v,w;
};
vector<node> G[M+N];
ll fdis[N][N];
ll fg[N][N];
node ls[M];
void solve(){
	for(int i=1;i<=n;i++){
		int ct;
		cin>>ct;
		for(int j=1;j<=ct;j++){
			int v,w;
			cin>>v>>w;
			G[v].push_back({m+i,w});
			G[m+i].push_back({v,w});
		}
	}
	memset(fg,0x3f,sizeof fg);
	for(int i=1;i<=m;i++){
		int ct=0;
		for(auto e:G[i]) ls[++ct]=e;
		for(int j=1;j<=ct;j++){
			node x1=ls[j];
			for(int k=j;k<=ct;k++){
				node x2=ls[k];
				fg[x1.v-m][x2.v-m]=min(fg[x1.v-m][x2.v-m],x1.w+x2.w);
				fg[x2.v-m][x1.v-m]=min(fg[x1.v-m][x2.v-m],x1.w+x2.w);
			}
		}
	}
	for(int i=1;i<=n;i++) fg[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				fg[i][j]=min(fg[i][k]+fg[k][j],fg[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fdis[i][j]=fg[i][j];
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	memset(fdis,0x3f,sizeof fdis);
	solve();
	while(q--){
		int l,r;
		cin>>l>>r;
		ll ans=2e18;
		for(auto e1:G[l]){
			for(auto e2:G[r]){
				ans=min(ans,e1.w+e2.w+fdis[e1.v-m][e2.v-m]);
				//cout<<e1.v<<" "<<e2.v<<" "<<fdis[e1.v-m][e2.v-m]<<" "<<e1.w<<" "<<e2.w<<" ";
			}
		}
		cout<<ans+a[l]+a[r]<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
