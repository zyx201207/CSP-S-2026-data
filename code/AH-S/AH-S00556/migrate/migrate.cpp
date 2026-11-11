#include<bits/stdc++.h>
using namespace std;
long long q,c,n,d,a[505],i,j,k,f[505][505],ans,cnt;
long long t,dp[505][505],ch,x1,x2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> q;
	if(c == 13 || c == 14){
		while(q--){
			ans = 0;
			cin >> n >> d;
			for(i=1;i<=n;i++)cin >> a[i];
			for(i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					ch = i;
					break;
				}
			}
			for(i=ch+1;i<=n;i++){
				auto it1=lower_bound(a+1,a+i+1,a[i]-d)-1;
				auto it2=upper_bound(a+1,a+ch+1,a[ch]-d);
				ans += it2-it1;
			}
			cout << ans << endl;
		}
		return 0;
	}
	while(q--){
		ans = 0;
		cin >> n >> d;
		for(i=1;i<=n;i++)cin >> a[i];
		for(i=1;i<=n;i++)f[i][i] = 0;
		for(i=1;i<=n;i++)dp[i][i] = 1;
		for(j=2;j<=n;j++){
			for(i=j-1;i>=1;i--){
				if(a[j]-a[i] <= d){
					f[i][j] = 1;
					continue;
				}
				f[i][j] = INT_MAX;
				for(k=j-1;k>i;k--){
					f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		for(j=2;j<=n;j++){
			for(i=j-1;i>=1;i--){
				dp[i][j] = 0;
				if(f[i][j] == 1)dp[i][j] = 1;
				else{
					for(k=j-1;k>i;k--){
						if(f[i][k]+f[k][j]==f[i][j]&&f[i][k]==1){
							t = dp[i][k]*dp[k][j];
							dp[i][j]+=t;
						}
					}
				}
				if(dp[i][j] == 2)ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
