#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,k[511],dp[51111],w[51111],a[511][51111],t[511][51111];
vector <int> g[51111];
void spfa(int x){
	queue <int> q;
	memset(dp,0x3f,sizeof(dp));
	q.push(x);
	dp[x]=w[x];
	while (!q.empty()){
		int p=q.front();
		q.pop();
		for (int i=0;i<g[p].size();i++){
			if (dp[g[p][i]]>dp[p]+t[p][i]){
				dp[g[p][i]]=dp[p]+t[p][i];
				q.push(g[p][i]);
			}
		}
	}
	return ;
}
signed main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	for (int i=1;i<=n;i++){
		cin >> k[i] >> a[i][1] >> t[i][1];
		for (int j=2;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			g[a[i][j]].push_back(a[i][j-1]);
			g[a[i][j-1]].push_back(a[i][j]);
		}
	}
	while (q--){
		int x,y;
		cin >> x >> y;
		spfa(x);
		cout << dp[y]+w[y] << endl;
	}
	return 0;
} 
