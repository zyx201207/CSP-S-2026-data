#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],b[500005];
bool check(long long x){
	for(int i=1;i+x-1<=n;i++){
		if(m>=x*a[i+x-1]-b[i+x-1]+b[i-1]){
//			cout<<i<<' '<<x<<' '<<x*a[i+x-1]-b[i+x-1]+b[i-1]<<' '<<m<<'\n';
			return true;
		}
	}
	return false;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}
