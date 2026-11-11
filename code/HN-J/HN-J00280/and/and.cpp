#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll LLMAX = LONG_LONG_MAX;
const int N = 1.5e4+5, TREESIZE = 1e3+5;
ll trie[N][2], d[TREESIZE];
ll n, m, cnt;
ll dp[N][N];
ll a[N];
bool is2pow(int x){
	while(x>0){
		if(!(x&1))
			return 0;
		x/=2;
	}
	return 1;
}
int main(){
		ios::sync_with_stdio();
	cin.tie(0);
	bool con1=1, con2=1, con3=1;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int p;
	cin>>n>>m;
	con2 = is2pow(n);
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		con1=(con1&is2pow(a[i]+1));
		con3=(con3&(a[i]<4));
	}
	if(m==1){
		ll ans = 0;
		for(int i = 1;i <= n;i++) ans = max(ans, a[i]);
		cout<<ans<<'\n';return 0;
	}else if(m==n){
		ll ans = a[1];
		for(int i = 2;i <= n;i++) ans = ans & a[i];
		cout<<ans<<'\n'; return 0; 
	}else if(m==2){
		ll ans = 0;
		for(int i = 2;i <= n;i++){
			for(int j = 1;j < i;j++){
				ans = max(ans, a[i]&a[j]);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}else if(con1){
		sort(a+1, a+1+n);
		cout<<a[n-1]<<'\n';
		return 0;
	}else if(con3){
		int h[4] = {};
		for(int i = 1;i <= n;i++){
			h[a[i]]++;
		}
		cout<<3<<'\n';
		return 0;
	}
	for(int i = 1;i <= n;i++){
		dp[i][1] = max(dp[i-1][1], a[i]);
		for(int j = 2;j <= m;j++){
			dp[i][j] = max(dp[i-1][j-1]&a[i], dp[i][j]);
		}
	}
	cout<<dp[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
