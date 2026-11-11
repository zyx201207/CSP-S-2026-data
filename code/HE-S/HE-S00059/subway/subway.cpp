#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500;
const int M=5e5;
const int K=5e5;
ll c,n,m,d,q,w[M+5],x,y,ans;
ll k[N+5],id[N+5][K+5];
vector<int> a[N+5],t[N+5];
//c:测试点数 n:地铁路线数 m:地铁站数 d:每个地铁站最多被几条路线经过
//q:出行计划数  w[i] 从i地铁站走到站厅需要的时间
// k[i] 第i条路线经过的地铁站数
// a[i][j] 第i条线路经过的第j个地铁站 
// t[i][j] 在第a[i][j]个地铁站,从站厅走到第i条线路的站台需要的时间 
void work(ll x,ll yy_t=0){//当前在地铁站x 
	for(ll i=1;i<=n;i++){//第i条路线 
		if(id[i][x]==-1) continue;
		if(id[i][y]!=-1) ans=min(ans,yy_t+t[i][id[i][x]]+t[i][id[i][y]]);
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x) continue;
			work(x,yy_t+t[i][id[i][x]]);
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(id,-1,sizeof(id));
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll A,T;
			cin>>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
			id[i][a[i][j]]=j;
		}
	}
	while(q--){
		ans=LLONG_MAX;
		cin>>x>>y;
		work(x);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
