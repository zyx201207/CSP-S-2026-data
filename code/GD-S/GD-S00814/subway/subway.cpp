#include<bits/stdc++.h>
#define int long long
using namespace std;
int T=1,c,n,m,d,q,w[500010],bj[510][510],an[510][510];
struct tt{
	int id,ti;
	friend bool operator < (tt a,tt b){
		return a.id<b.id;
	}
};
vector<tt>a[500010];
vector<int>b[510];
struct tc{
	int id,fa;
};
queue<tc>e;
void op(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
void work(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			an[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++) e.push({i,i}),an[i][i]=0;
	while(!e.empty()){
		auto u=e.front();
		e.pop();
		for(auto v:b[u.id]){
			if(an[u.fa][u.id]+bj[u.id][v]>an[u.fa][v]) continue;
			an[u.fa][v]=an[u.fa][u.id]+bj[u.id][v];
			e.push({v,u.fa});
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int l=0;l<a[i].size();l++){
			for(int r=l+1;r<a[i].size();r++){
				auto x=a[i][l],y=a[i][r];
				if(!bj[x.id][y.id]){
					b[x.id].push_back(y.id);
					b[y.id].push_back(x.id);
					bj[x.id][y.id]=bj[y.id][x.id]=x.ti+y.ti;
				}else{
					bj[x.id][y.id]=bj[y.id][x.id]=min(bj[x.id][y.id],x.ti+y.ti);
				}
			}
		}
	}
	work();
	while(q--){
		int s,t,ans=1e18;
		cin>>s>>t;
		for(auto x:a[s]){
			for(auto y:a[t]){
				ans=min(ans,w[s]+x.ti+an[x.id][y.id]+y.ti+w[t]);
			}
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	op();
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	while(T--){
		solve();
	}
}
