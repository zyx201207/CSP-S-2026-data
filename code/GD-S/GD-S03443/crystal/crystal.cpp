#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],prefix[N],sum,ans=-20;
bool chk(int x){
	for(int i=x;i<=n;i++){
		if(prefix[i]-prefix[i-x-1]+m>=a[i]*x) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		//cout << "l="<<l<<" r="<<r<<" mid="<<mid<<"\n";
		ans=mid;
		if(chk(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	//cout << l << " " << r<<"\n";
	if(ans==-20) r=1;
	cout << r;
	return 0;
}
