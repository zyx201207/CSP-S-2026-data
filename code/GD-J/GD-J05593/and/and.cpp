#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
int n,m,ans=0;
int a[2*N];
int dp[2*N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	if(m==1){
		sort(a+1,a+n);
		cout << a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i] = max(dp[i],a[i]&a[j]);
				ans = max(ans,dp[i]);
			}
		}
		cout << ans;
		return 0;
	}
    if(m==n){
    	ans = a[1];
    	for(int i=2;i<=n;i++){
    		ans = ans&a[i];
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n);
	reverse(a+1,a+n);
	cout << a[m];
	return 0;
} 
