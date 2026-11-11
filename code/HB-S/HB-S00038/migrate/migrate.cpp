#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5005;
int c,t,n,m,arr[maxn],dp[maxn][maxn],diff[maxn];
bool check(int l,int r){
	int step = 0ll;
	int left = l,right = r;
	while(true){
		int L = left,R = right,ans = 0;
		while(L <= R){
			int mid = (L+R) >> 1;
			if(arr[mid]-arr[left] <= m) ans = mid,L = mid+1;
			else R = mid-1;
		}
		if(ans == right){
			step++;
			break;
		}
		step++;
		left = ans+1;
	}
	for(int i = l;i <= r;i++)
		for(int j = 0;j <= step;j++) dp[i][j] = 0;
	dp[l][0] = 1;
	for(int i = l+1;i <= r;i++){
		for(int j = 1;j <= step;j++){
			for(int pre = l;pre < i;pre++){
				dp[i][j] += dp[pre][j-1];
			}
		}
	}
	return (dp[r][step] == 2 ? 1 : 0);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1;i <= n;i++){
			cin >> arr[i];
			if(i != n) diff[i-1] = (arr[i]-arr[i-1] > m ? 1 : 0);
		} 
		for(int i = 1;i < n;i++) diff[i] = diff[i-1] + diff[i];
		int ans = 0ll;
		for(int l = 1;l <= n;l++){
			for(int r = l+1;r <= n;r++){
				if(diff[r-1]-diff[l-1] > 0) continue;
				if(check(l,r)) ans++;
			} 
		}
		//cout << endl;
		cout << ans << '\n';
	}
	return 0;
}