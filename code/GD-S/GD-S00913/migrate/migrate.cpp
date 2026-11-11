#include<bits/stdc++.h>
#define int long long
#define No ios::sync_with_stdio(0);
#define TLE cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=5e3+10;
void _freopen(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
int c;
int f[N][N];
int b[N];
int dp[N][N];	
int a[N];
int n,m;
void dfs(int s,int x,int now){
	if(now==f[s][x]){
		dp[s][x]++;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]>m) break;
		dfs(s,i,now+1);
	}
}
void solve(){
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(f,INF,sizeof f);
	memset(b,INF,sizeof b);
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j]=(a[j]-a[i]+m-1)/m;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) f[1][j]=min(f[1][j],f[1][i]+f[i][j]);
	}
	
	for(int i=1;i<=n;i++){
		dfs(i,i,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dp[i][j]==2) ans++;
		}
	}
	//cout<<f[1][n]<<endl;
	cout<<ans<<endl;
	
}
signed main(){
	No TLE
	_freopen();
	int T=1;
	cin>>c>>T;
	while(T--){
		solve();
	}
}

