#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
bool bbb;
const int N=5e5+5,M=505;
ll c,n,m,d,q,w[N],k[M],dis[M][M];
vector<PII> v[N];
void fast(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return;
}
bool eee;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fast();
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
		for(auto j:v[i])
			for(auto k:v[i]) dis[j.first][k.first]=min(dis[j.first][k.first],j.second+k.second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	while(q--){
		ll x,y,ans=inf;
		cin>>x>>y;
		for(auto j:v[x])
			for(auto k:v[y]) ans=min(ans,dis[j.first][k.first]+w[x]+w[y]+j.second+k.second);
		cout<<ans<<endl;
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
