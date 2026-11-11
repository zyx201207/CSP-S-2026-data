#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,q;
struct node{
	ll x,t;
};
vector<node>x[205];
vector<node>y[500005];
int w[500005];
ll a[205][205];
ll dis[205][205];
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(a,0x3f,sizeof a);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int u,t;
			cin>>u>>t;
			x[i].push_back({u,t});
			y[u].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<y[i].size();j++){
			for(int k=j+1;k<y[i].size();k++){
				a[y[i][k].x][y[i][j].x]=
				a[y[i][j].x][y[i][k].x]=
				min(a[y[i][j].x][y[i][k].x],y[i][j].t+y[i][k].t);
			}
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=a[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	while(q--){
		int x,z;
		cin>>x>>z;
		ll mn=1e15;
		for(auto it:y[x]){
			for(auto ti:y[z]){
				mn=min(it.t+ti.t+dis[it.x][ti.x],mn);
			}
		}
		cout<<mn+w[x]+w[z]<<endl;
	}
	return 0;
}

