#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5+10;
int n, m, a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	int ans = INT_MIN;
	int l = 1, r= 1;
	while(l<=r){
		int sum = 0;
		for(int j = l; j< r;j++){
			sum += a[r] - a[j];
			if(sum >= m) break;
		}
		if(sum <= m){
			ans = max(ans, r-l+1);
			r++;
		}
		else{
			l++;
		}
		if(l == n or r == n) break;
	}
	cout<< ans;
	return 0; 
} 
