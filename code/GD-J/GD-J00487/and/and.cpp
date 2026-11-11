#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int dp[N];
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int ans = 0;
	sort(a+1,a+1+n);
	if(m == 1){
		for(int i = 1;i<=n;i++){
			ans = max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}else if(m == 2){
		for(int i = 1;i<=n;i++){
			for(int j =1 ;j<=n;j++){
				if(i!=j){
					ans = max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}else if(m ==n){
		ans = a[1];
		for(int i =2;i<n;i++){
			ans = ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(m == n-1){
		int ans1 = a[1];
		int ans2 = a[2];
		for(int i = 2;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(j!=i){
					ans1 = ans1&a[j];
				}
			}
		}
		for(int i = 2;i<=n;i++){
			ans2 = ans2&a[i];
		}
		cout<<max(ans1,ans2);
		return 0;
	}
	return 0;
}
