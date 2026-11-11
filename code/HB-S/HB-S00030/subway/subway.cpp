#include <bits/stdc++.h>
using namespace std;
long long n,m,h,o,c,w[500010],k,x,y,d[500010];
vector < pair < long long , long long > > e[510],a[500010];
struct node{long long id,x,y,ans;}ans[100010];
bool cmp1(node x,node y){return x.x<y.x;}
bool cmp2(node x,node y){return x.id<y.id;}
void dij(long long x){
	priority_queue < pair < long long , long long > , vector < pair < long long , long long > > , greater < pair < long long , long long > > > q;
	q.push({x,w[x]});
	for(long long i=1;i<=m;++i) d[i]=1e18;
	d[x]=w[x];
	while(!q.empty()){
		long long x=q.top().first,w=q.top().second;
		q.pop();
		if(w>d[x]) continue;
		for(long long i=0;i<a[x].size();++i){for(long long j=0;j<e[a[x][i].first].size();++j){
			if(e[a[x][i].first][j].first!=x&&w+a[x][i].second+e[a[x][i].first][j].second<d[e[a[x][i].first][j].first]){
				d[e[a[x][i].first][j].first]=w+a[x][i].second+e[a[x][i].first][j].second;
				q.push({e[a[x][i].first][j].first,w+a[x][i].second+e[a[x][i].first][j].second});
			}
		}}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>n>>m>>o>>h;
	for(long long i=1;i<=m;++i) cin>>w[i];
	for(long long i=1;i<=n;++i){
		cin>>k;
		for(long long j=1;j<=k;++j){
			cin>>x>>y;
			e[i].push_back({x,y});
			a[x].push_back({i,y});
		}
	}
	for(long long i=1;i<=h;++i){
		cin>>x>>y;
		ans[i].id=i,ans[i].x=x,ans[i].y=y;
	}
	sort(ans+1,ans+h+1,cmp1);
	for(long long i=1;i<=h;++i){
		if(ans[i].x!=ans[i-1].x) dij(ans[i].x);
		ans[i].ans=d[ans[i].y]+w[ans[i].y];
	}
	sort(ans+1,ans+h+1,cmp2);
	for(long long i=1;i<=h;++i) cout<<ans[i].ans<<"\n";
	return 0;
}
