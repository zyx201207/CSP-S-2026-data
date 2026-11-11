#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAXN=125255,MAXM=5e5+5;
ll w[MAXN];
vector<pair<int,int> >line[505];
vector<pair<int,int> >v[MAXN];
bool vl[505],vs[MAXM];
ll ans=LLONG_MAX;
void dfs(int s,int e,ll time)
{
	if(s==e){
		if(time<ans) ans=time;
		return;
	}
	if(time>=ans) return;
	for(auto p:v[s]){
		int l=p.first,w1=p.second;
		if(vl[l]) continue;
		vl[l]=1;
		for(auto i:line[l]){
			int sta=i.first,w2=i.second;
			if(!vs[sta]){
				vs[sta]=1;
				dfs(sta,e,time+w1+w2);
				vs[sta]=0;
			}
		}
		vl[l]=0;
	}
}
int main()
{
	std::cin.tie(0)->sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a,t;
			cin>>a>>t;
			line[i].push_back({a,t});
			v[a].push_back({i,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=LLONG_MAX;
		vs[x]=1;
		dfs(x,y,w[x]+w[y]);
		cout<<ans<<endl;
		vs[x]=0;
	}
	return 0;
}
