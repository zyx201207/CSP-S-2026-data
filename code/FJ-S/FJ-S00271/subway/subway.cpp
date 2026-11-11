#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
const int N=505;
int c,n,m,d,q,a,t,x,y,len,w[M];
ll ans,dis[N][N];
vector<pair<int,int> >V[M];
void minn(ll &x,ll y){
	x=min(x,y);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>a>>t;
			V[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1e18;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		len=(int)V[i].size();
		for(int j=1;j<len;j++)
			for(int k=0;k<j;k++){
				minn(dis[V[i][j].first][V[i][k].first],V[i][j].second+V[i][k].second);
				dis[V[i][k].first][V[i][j].first]=dis[V[i][j].first][V[i][k].first];
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				minn(dis[i][j],dis[i][k]+dis[k][j]),
				dis[j][i]=dis[i][j];
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(auto i:V[x])
			for(auto j:V[y])
				minn(ans,i.second+j.second+dis[i.first][j.first]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
