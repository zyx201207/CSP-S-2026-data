#include<bits/stdc++.h>
using namespace std;
#define int long long
struct bai{
	int sum;
	int pre;
	char letr;
}a[210000];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);
	int n; cin>>n;
	int z = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].letr;
		z += a[i].sum;
		a[i].pre = a[i-1].pre + a[i].sum;
	}
	int l = 1,r = z;
	int ans = 0;
	for(int i=1,j=n;i<=j;i++){
		while(l <= a[i].pre){
			if(l >= r) break;
			if(a[i].letr != a[j].letr){
				int mv = min(a[i].pre-l+1,r-a[j].pre+a[j].sum);
				ans += mv;
				l += mv,r -= mv;
			}
			else{
				int mv = min(a[i].pre-l+1,r-a[j].pre+a[j].sum);
				l += mv,r -= mv;
			}
			while(a[j-1].pre >= r) j--;
		}
		// cout<<i<<' '<<j<<' '<<l<<' '<<r<<' '<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
//copy by baibai__
//100pts