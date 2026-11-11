#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PI;
const int M=5e5+1000;
ll C,n,m,d,q,w[M],mx,dis[M];
vector<PI> v1[M],v2[M*10];
bool cmp(PI x,PI y){
	return v2[x.first][x.second].second<v2[y.first][y.second].second;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		ll k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			ll a,t;
			scanf("%lld%lld",&a,&t);
			v1[a].push_back({m+i,j});
			v2[m+i].push_back({a,t});
			v2[a].push_back({m+i,t});
		}
	}
	for(int i=1;i<=m;i++)sort(v1[i].begin(),v1[i].end(),cmp);
	while(q--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=m+n;i++)dis[i]=1e18;
		priority_queue<PI,vector<PI>,greater<PI> > q1;
		dis[v1[x][0].first]=v2[v1[x][0].first][v1[x][0].second].second;
		q1.push({dis[v1[x][0].first],v1[x][0].first});
		for(int i=1;i<=m+n;i++){
			ll mi=q1.top().first,no=q1.top().second;
			q1.pop();
			ll len=v2[no].size();
			for(int j=0;j<len;j++){
				if(dis[v2[no][j].first]>mi+v2[no][j].second)dis[v2[no][j].first]=mi+v2[no][j].second;
			}
		}
		printf("%lld\n",dis[y]+w[x]+w[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
