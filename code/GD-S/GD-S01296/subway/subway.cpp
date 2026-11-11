#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
using ll=long long;
const int maxn=5e2+2,maxm=5e5+5;
const ll infll=0x3f3f3f3f3f3f3f3fLL;
struct Station{
	int id;
	ll time;
	Station(){}
	Station(int inpid,ll inptime){
		id=inpid;
		time=inptime;
	}
};
vector<Station> subw[maxn];
vector<pair<int,ll>> dit[maxm];
int k[maxn];
ll w[maxm],g[maxn][maxn];
bool cmp(const Station &x,const Station &y){
	return x.id<y.id;
}
void floyd(int n){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			Station crs;
			cin>>crs.id>>crs.time;
			subw[i].push_back(crs);
			dit[crs.id].push_back(make_pair(i,crs.time));
		}
		sort(subw[i].begin(),subw[i].end(),cmp);
	}
	for(int u=1;u<=n;u++){
		for(int v=u+1;v<=n;v++){
			ll edt=infll;
			for(int i=0,j=0;i<subw[u].size()&&j<subw[v].size();){
				if(subw[u][i].id==subw[v][j].id){
					edt=min(edt,subw[u][i].time+subw[v][j].time);
					i++,j++;
				}
				else if(subw[u][i].id<subw[v][j].id)i++;
				else j++;
			}
			g[u][v]=g[v][u]=edt;
		}
	}
	floyd(n);
	while(q--){
		int u,v;
		cin>>u>>v;
		ll res=infll;
		for(int i=0;i<dit[u].size();i++){
			for(int j=0;j<dit[v].size();j++){
				res=min(res,w[u]+dit[u][i].second+g[dit[u][i].first][dit[v][j].first]+dit[v][j].second+w[v]);
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
