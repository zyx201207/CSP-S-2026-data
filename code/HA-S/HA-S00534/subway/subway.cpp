#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,l,r) for(ll i=l;i<=r;i++)
#define rfr(i,l,r) for(ll i=l;i>=r;i--)
#define lwq return

const ll N=500;
const ll M=1050;
const ll Q=1e5+50;
struct road{
	ll line,to;
};
ll c,n,m,d,q,w[M],k[M],a[M][M],t[N][M],x[Q],y[Q],ans[M];
vector<road>G[M];

void init(){
	cin>>c>>n>>m>>d>>q;
	fr(i,1,m)	cin>>w[i];
	fr(i,1,n){
		cin>>k[i];
		fr(j,1,k[i]) cin>>a[i][j]>>t[i][j];
		fr(ttt,1,k[i]-1)
			fr(tttt,ttt+1,k[i])
				G[a[i][ttt]].push_back({i,a[i][tttt]}),G[a[i][tttt]].push_back({i,a[i][ttt]});
	}
	fr(i,1,q)	cin>>x[i]>>y[i];
}

struct node{
	ll nw,p;
};

ll bfs(ll x,ll y){
	fr(i,1,m)	ans[i]=1e18;
	queue<node> q;
	ans[x]=0;
	q.push({x,0});
	while(!q.empty()){
		node tt=q.front();q.pop();
		for(road i:G[tt.nw]){
			if(ans[i.to]>tt.p+t[i.line][tt.nw]+t[i.line][i.to]){
				ans[i.to]=tt.p+t[i.line][tt.nw]+t[i.line][i.to];
				q.push({i.to,ans[i.to]});
			}
		}
	}
	lwq ans[y]+w[x]+w[y];
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	fr(i,1,q) cout<<bfs(x[i],y[i])<<"\n";
	lwq 0;
}
