#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7;
using ll=long long;
map<ll,ll>cost1[500010];
ll cnt1[500010];
ll dp[600][600];//在第i条路线上换到第j条路线的最小花费
vector<int>b[500020];
ll c[500001];
ll a[501000];
vector<int>t[500001];
vector<int>l[501];
ll dis[601][601];
ll vis[601];
ll cc,n,m,d,q;
void dijkstra(int dq){
	dis[dq][dq]=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		ll minn=1e18;
		ll bianh=1e18;
		for(int j=1;j<=n;j++){
			if(dis[dq][j]<minn&&vis[j]==0){
				minn=dis[dq][j];
				bianh=j;
			}
		}
		if(minn==1e18)break;
		vis[bianh]=1;
		for(auto j:l[bianh]){
			//cout<<dq<<" "<<j<<":"<<dis[dq][j]<<endl;
			dis[dq][j]=min(dis[dq][j],dis[dq][bianh]+dp[bianh][j]);
			//cout<<dq<<" "<<j<<":"<<dis[dq][j]<<endl;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
		ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//memset(dis,1e9,sizeof(dis));
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=c[i];j++){
			int jj,jjj;
			cin>>jj>>jjj;
			t[jj].push_back(i);
			b[i].push_back(jj);
			cost1[jj][i]=jjj;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
	    for(auto j:b[i]){
			for(auto k:t[j]){
				if(k==i)continue;
				dp[i][k]=min(dp[i][k],cost1[j][i]+cost1[j][k]);
			}
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
			if(dp[i][j]!=1e18){
				l[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
			
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<i<<" "<<j<<":"<<dis[i][j]<<endl;
		}
  	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		ll ans=1e18;
		for(auto i:t[xr]){
			for(auto j:t[yr]){
				ans=min(ans,a[xr]+a[yr]+dis[i][j]+cost1[xr][i]+cost1[yr][j]);
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
//Oct31==Dec25?
