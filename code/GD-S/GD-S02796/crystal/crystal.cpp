#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
long long n,m;
long long a[maxn],sum[maxn];
long long ans,sum1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	sum[1] = a[1];
	for(int i = 2;i <= n;i++){
		sum[i] = (i-1)*(a[i]-a[i-1])+sum[i-1];
	}
	for(int r = 2;r <= n;r++){
		for(int l = 1;l < r;l++){
			int k = r-l+1;
			sum1 = (sum[r]-sum[l])-(l-1)*(a[r]-a[l]);
			if(sum1 <= m){
				if(ans < k){
					ans = k;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
