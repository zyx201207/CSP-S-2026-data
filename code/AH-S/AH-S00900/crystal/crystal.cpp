// It's @Fp0cY1tZ6Mn4Rd_ again.
// Happy Halloween. Oct31==Dec25?
// How can I solve this prooblem?

//upd: Wasting a lot of time, I finally solve this problem (maybe :-(
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],s[N],n,m;
bool check1(int x){
	ll ans=m+1;
	for(int i=1,j,k;i+x-1<=n;i++){
		j=i+x-1,k=(i+j)>>1;
		ll res=(k*2-i-j)*a[k]-(s[k-1]-s[i-1])+(s[j]-s[k]);
//		cout<<i<<" "<<j<<" "<<res<<"\n"; 
		ans=min(ans,res);
	}
	return ans<=m;
}
bool check(int x){
	ll ans=m+1;
	for(int i=1,j;i+x-1<=n;i++){
		j=i+x-1;
		ll res=(j-i)*a[j]-(s[j-1]-s[i-1]);
//		cout<<i<<" "<<j<<" "<<res<<"\n"; 
		ans=min(ans,res);
	}
	return ans<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=0,r=n+1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<"\n";
	return 0;
}
