#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(n) cout << #n << " = " << n << "\n";
#define deb(n) cout << #n << " = " << n << "    ";
#define div() cout << "\n---------------------\n";
int n,m;int ans;
int a[500005];
int sum[500005];
inline int query(int l,int r){return sum[r]-sum[l-1];}
inline bool check(int mid){
	for(int i = mid;i <= n;i++){
		if((mid-1)*(a[i])-query(i-mid+1,i-1) <= m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){cin >> a[i];}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){sum[i] = sum[i-1]+a[i];}
	int l = 1,r = n,mid;
	while(l <= r){
		mid = (l+r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	cout << ans;
	return 0;
}
