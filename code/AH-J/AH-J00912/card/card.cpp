#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,ans[300005],a[500005],k,e[300005],a1[5005],sum;
long long x[300005];
bool dp[5005][3005];
const long long cheat = 15000000;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(i=1;i<=n;i++)cin >> a[i];
	k = a[1];
	for(i=2;i<=n;i++){
		if(a[i] < k)break;
		k = max(k,a[i]);
	}
	if(i<=n && n*m<=cheat){
		for(i=1;i<=n+1;i++)
			for(j=1;j<=m+1;j++)dp[i][j] = 0;
		for(i=n;i>=1;i--){
			if(!x[a[i]]){
				k = i+1;
				x[a[i]] = i;
			}
			else k = x[a[i]];
			for(j=1;j<=m;j++){
				dp[i][j] = (a[i]==j||dp[k][j]);
				if(dp[i][j])ans[j]++;
			}
		}
		for(i=1;i<=m;i++)cout << ans[i] << ' ';
	}
	else if(i==n+1){
		k = 1;
		for(i=2;i<=n;i++){
			if(a[i] != k){
				e[k] = i-1;
				k = a[i];
			}
		}
		e[m] = n;
		for(i=1;i<=m;i++)cout << e[i] << ' ';
	}
	else{
		long long n1;
		k = a[1];
		j = 1;
		a1[j] = k;
		for(i=2;i<=n;i++){
			if(a[i] != k){
				ans[k] = max(ans[k],sum);
				k = a[i];
				j++;
				a1[j] = k;
				continue;
			}
			sum++;
		}
		n1 = j;
		for(i=n1;i>=1;i--){
			if(!x[a1[i]]){
				k = i+1;
				x[a1[i]] = i;
			}
			else k = x[a1[i]];
			for(j=1;j<=m;j++){
				dp[i][j] = (a1[i]==j||dp[k][j]);
				if(dp[i][j])ans[j]++;
			}
		}
		for(i=1;i<m;i++)cout << ans[i] << ' ';
		cout << n;
	}
	return 0;
}
