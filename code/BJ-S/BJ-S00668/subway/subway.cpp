#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXM=500000,MAXN=500,MAXQ=100000;
int caseid;
int n,m,d,q,v,t;
int w[MAXM+10],k[MAXN+10],x[MAXQ+10],y[MAXQ+10];
int dp[MAXN+10][MAXN+10];
struct node{
	int v;
	int t;
};
node tmp,tmp1;
vector<node> a[MAXN+10];
vector<node> g[MAXM+10];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>caseid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>v>>t;
			tmp.v=v,tmp.t=t;
			tmp1.v=i,tmp1.t=t;
			a[i].push_back(tmp);
			g[v].push_back(tmp1);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dp[i][j]=0;
			else dp[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int fr=g[i][j].v,to=g[i][k].v,t1=g[i][j].t,t2=g[i][k].t;
				dp[fr][to]=min(dp[fr][to],t1+t2);
				dp[to][fr]=min(dp[to][fr],t1+t2);
			}
		}
	}
	for(int lim=1;lim<=n;lim++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][lim]+dp[lim][j]);
			}
		}
	}
	for(int l=1;l<=q;l++){
		int ans=1e18;
		for(int i=0;i<g[x[l]].size();i++){
			for(int j=0;j<g[y[l]].size();j++){
				ans=min(ans,dp[g[x[l]][i].v][g[y[l]][j].v]+g[x[l]][i].t+g[y[l]][j].t);
			}
		}
		cout<<ans+w[x[l]]+w[y[l]]<<endl;
	}
	return 0;
}
//O(n^3+md^2+qd^2)
