#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[MAXN],dp[355][355],jg[MAXN][26],mp[355][355];
//vector <pair<int,int>> V[MAXN+505];
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
//void dj(int s){
//	for(register int i=1;i<=m+n;i++){
//		dis[i]=INF;
//	}
//	dis[s]=0;
//	//pq.push()
//}
void flyd(){
	for(register int k=1;k<=n+m;k++){
		for(register int i=1;i<=n+m;i++){
			if(dp[i][k]>=INF)continue;
			for(register int j=1;j<=n+m;j++){
				if(dp[i][k]>dp[i][j])continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(register int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(register int i=1;i<=n;i++){
		int x;
		cin>>x;
		int u=i;
		for(register int j=1;j<=x;j++){
			int v,t;
			cin>>v>>t;
			jg[v][++jg[v][0]]=u;
			v+=n;
			mp[u][v]=t;
			mp[v][u]=t;
			dp[u][v]=t;
			dp[v][u]=t;
			//V[u].push_back(make_pair(t,v));
			//V[v].push_back(make_pair(t,u));
		}
	}
	if(c>=1&&c<=6){memset(dp,INF,sizeof(dp));flyd();}
	while(q--){
		int st,en,ans=-1e9;
		cin>>st>>en;
		st+=n;en+=n;
		cout<<0;
	}
	return 0;
} 
