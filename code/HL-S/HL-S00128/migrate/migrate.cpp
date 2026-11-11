#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e6+1;
int c,t;
int x[N],diff[N],dp[N];
int cnt,idx;
void dfs(int u,int n,int d,int sum){
	if(u >= n){
		if(sum < idx){
			idx = sum;cnt = 1;
		}
		else if(sum==idx)cnt++;
	//	cout <<sum<<endl;
		return ;
	}
	for(int i = u+1;i <= n;i++){
		if(abs(x[i]-x[u]) > d)break;
		dfs(i,n,d,sum+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c>>t;
	while(t--){
		int n,d;cin >>n>>d;cnt = 0,idx = 1e18;
		memset(x,0,sizeof(x));
		for(int i = 1;i <= n;i++){
			cin >>x[i];
		}	
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){	
				dfs(i,j,d,0);
				if(cnt == 2)ans++;
				//cout <<cnt<<endl;
				cnt = 0;
				idx = 1e18;
			}
		}
		cout <<ans<<endl;
	}
	return 0;
}
