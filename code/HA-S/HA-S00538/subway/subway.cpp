#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int A=5e5+5;
struct S{
	int y;
	ll t;
};
vector<S>a[A+505];
ll g[505][505];
ll w[A];
int c,n,m,d,q;
struct SP{
	int x;
	ll t;
	friend bool operator < (SP x,SP y){
		return x.t>y.t;
	}
};
struct S1{
	int x, y;
	ll t;
};
void bfs(int st){
	queue<S1>q1;
	q1.push({st,0});
	while(!q1.empty()){
		int x=q1.front().x,x1=q1.front().y;
		ll t=q1.front().t;
		q1.pop();
		int z=a[x].size();
		for(int i=0;i<z;i++){
			int y=a[x][i].y;
			if(y<=m)q1.push({y,x,t+a[x][i].t});
			else if(y!=x1){
				g[y-m][x1-m]=g[x1-m][y-m]=min(g[x1-m][y-m],t+a[x][i].t);
				//cout<<y<<" "<<x1<<" "<<x<<" "<<g[y-m][x1-m]<<"\n";
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int k,_x,_t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>_x>>_t;
			a[i+m].push_back({_x,_t});
			a[_x].push_back({i+m,_t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=(i==j ? 0 : 1e18);
	for(int i=1;i<=n;i++){
		bfs(i+m);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)g[j][i]=g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		ll ans=1e18;
		int z1=a[st].size(),z2=a[ed].size();
		for(int i=0;i<z1;i++){
			for(int j=0;j<z2;j++){
				//cout<<g[a[st][i].y-m][a[ed][j].y-m]<<";";
				ans=min(ans,g[a[st][i].y-m][a[ed][j].y-m]+a[st][i].t+a[ed][j].t);
			}
		}
		cout<<ans+w[st]+w[ed]<<'\n';
	}
	return 0;
}
