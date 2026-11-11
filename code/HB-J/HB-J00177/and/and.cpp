#include <bits/stdc++.h>
using namespace std;

int dp[2010][2010],n,m,mx = -1,sum = (1 << 20) - 1;
int a[200010];

int dfs(int pos,int cnt,int val){
	if(pos > n && cnt < m){
		return -1;
	}
	if(cnt == m){
		return val;
	}
	if(cnt == 0){
		return max(dfs(pos + 1,cnt + 1,a[pos]),dfs(pos + 1,cnt,0));
	}
	return max(dfs(pos + 1,cnt + 1,val & a[pos]),dfs(pos + 1,cnt,val));
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		mx = max(mx,a[i]);
		sum &= a[i];
	}
	if(m == 1){
		cout << mx;
		return 0;
	}
	if(m == n){
		cout << sum;
		return 0;
	}
	if(m == 2){
		mx = -1;
		for(int i = 1;i <= n - 1;i++){
			for(int j = i + 1;j <= n;j++){
				mx = max(mx,a[i] & a[j]);
			}
		}
		cout << mx;
		return 0;
	}
	
	cout << dfs(1,0,0);

	return 0;
}
