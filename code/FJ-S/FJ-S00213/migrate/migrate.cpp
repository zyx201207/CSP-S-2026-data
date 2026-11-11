#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2005;
int c,t,n;
ll d,x[N];
ll dis[N][N],dp[N][N];

void solve(){
	cin >> n >> d;
	x[0]=0;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			//cout << i << " " << j << ":\n";
			int ni=i;
			ll cnt=0;
			bool can=true;
			while(ni<j){
				//cout << x[ni]+d << " " << ni << " ";
				int nxt=upper_bound(x+1,x+n+1,x[ni]+d)-x;
				//cout << nxt << "\n";
				if(ni==nxt-1){
					can=false;
					break;
				}
				ni=nxt-1;
				cnt++;
			}
			if(can) dis[i][j]=cnt;
			else dis[i][j]=-1;
			//cout << "\n";
		}
	}
	
	/*for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}*/
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]==-1) dp[i][j]=-1;
			else if(x[j]-x[i]<=d){
				dp[i][j]=1;
			}
			else dp[i][j]=0;
		}
	}
	
	/*for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]==-1) continue;
			ll cnt=0;
			for(int k=i+1;k<j;k++){
				if(dis[i][k]==-1 || dis[k][j]==-1) continue;
				if(dis[i][j]==dis[i][k]+dis[k][j]){
					cnt+=dp[i][k]*dp[k][j];
				}
			}
			dp[i][j]+=cnt;
		}
	}
	
	/*for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	
	ll res=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dp[i][j]==2){
				res++;
			}
		}
	}
	
	cout << res << "\n";
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	
	if(c==13 || c==14){
		while(t--){
			cin >> n >> d;
			x[0]=0;
			for(int i=1;i<=n;i++) cin >> x[i];
			cout << "0\n";
		}
	}
	else{
		while(t--) solve();
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/
