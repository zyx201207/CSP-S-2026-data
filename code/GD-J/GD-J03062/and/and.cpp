#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n,m;
long long a[maxn],dp[maxn],w[22][22];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n==m){
		ans = a[1];
		for(int i = 2;i <= n;i++){
			ans &= a[i];
		}
		cout<<ans;
		return 0; 
	}
	if(m==1){
		for(int i = 1;i <= n;i++) ans = max(ans,a[i]);
		cout << ans;
		return 0; 
	}
	if(m==2){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				w[i][j] = a[i] & a[j];
				ans = max(ans,w[i][j]);
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 1;i  <= n;i++){
		for(int i = 1;i <= n;i++) ans = max(ans,a[i]);
		cout << ans;
		return 0;
	}
	return 0;
}
