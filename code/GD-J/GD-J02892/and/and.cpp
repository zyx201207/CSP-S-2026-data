#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 10;
int n,m;
ll a[N];
ll dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll max_num = 0;
	for(int i = 1 ; i <= n ; i ++){
		cin>>a[i];
		max_num = max(max_num,a[i]);
	}
	if(m == 1) {
		cout<<max_num;
		return 0;
	}
	ll ans = 0;
	if(m == 2){
		for(int i = 1 ; i <= n ; i ++){
			for(int j = i + 1 ; j <= n ; j ++){
				ans = max(ans,a[i]&a[j]);
			}
		}
	}
	
	cout<<ans;
	return 0;
}
