#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[500005];
int n,m;
int q[500005];
bool check(int mid){
	int s = 0;
	for(int i = 1;i <= mid;i++){
		s += a[mid]-a[i];
	}
	if(s <= m){
		return 1;
	}
	for(int i = mid;i <= n-1;i++){
		s+=(a[i+1]-a[i])*mid;
		s-=a[i+1]-a[i-mid+1];
		if(s <= m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int l = 1,r = n;
	int ans = 0;
	while(l <= r){
		int mid = (r-l)/2+l;
		if(check(mid)){
			l = mid+1;
			ans = max(ans,mid);
		}else{
			r = mid-1;
		}
	}
	cout << ans;
	return 0;
} 
