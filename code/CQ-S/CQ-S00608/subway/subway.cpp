#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define psb push_back
#define mid (l+r>>1)
#define endl '\n'

const int mxn=505,mxm=5e5+5;
const ll inf=1e18;
int n,m,cs,dd,t,a[mxm];
ll s,ds[mxn][mxn],f[mxn][mxn];
vector<pair<int,ll>>v[mxn],g[mxm];

void djst(){
	priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>>pq;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) ds[i][j]=inf;
		pq.push({ds[i][i]=0,{i,i}});
	}
	while(!pq.empty()){
		auto x=pq.top();
		pq.pop();
		if(x.F>ds[x.S.F][x.S.S]) continue;
		for(pii i:v[x.S.S]) if(x.F+(ll)i.S<ds[x.S.F][i.F]) pq.push({ds[x.S.F][i.F]=x.F+i.S,{i.F,x.S.F}});
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cs>>n>>m>>dd>>t;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int x,y,z,i=1;i<=n;i++){
		cin>>x;
		while(x--){
			cin>>y>>z;
			g[y].psb({i,z});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=inf;
	for(int i=1;i<=m;i++) for(pii j:g[i]) for(pii k:g[i]) f[j.F][k.F]=f[k.F][j.F]=min(f[j.F][k.F],(ll)j.S+k.S);
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) if(f[i][j]<inf) v[i].psb({j,f[i][j]}),v[j].psb({i,f[i][j]});
	djst();
	while(t--){
		int x,y;
		cin>>x>>y;
		s=inf;
		for(pii i:g[x]) for(pii j:g[y]) s=min(s,(ll)i.S+j.S+ds[i.F][j.F]+a[x]+a[y]);
		cout<<s<<endl;
	}
	return 0;
}
