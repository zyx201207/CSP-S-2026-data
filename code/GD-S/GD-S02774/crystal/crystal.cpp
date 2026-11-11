#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int a[N];
int cnt[N];
int n,m;

bool check(int mid){
	for(int i = 1;i<=n;i++){
		if(i + mid - 1 > n){
			break;
		}
		int tp = a[i + mid - 1];
		int sum = cnt[i + mid - 1] - cnt[i - 1];
		if(tp * mid - sum <= m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1 ;i<=n;i++){
		cin>>a[i];
	}
	sort(a + 1,a+n + 1);
	for(int i = 1 ;i<=n;i++){
		cnt[i] = cnt[i - 1] + a[i];
	}
	int l = 2,r = n;
	int res = 2;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(check(mid)){
			l = mid + 1;
			res = mid;
		}else{
			r = mid - 1;
		}
	}
	cout<<res;
	return 0;
}
