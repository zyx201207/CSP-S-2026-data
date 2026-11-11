#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int cha[500005],p[500005];
long long ans;
bool check(int x){
	for(int l=1;l<=n-x;l++){
		int r = l+x-1;
		if(m>=p[r]-p[l-1]){
//			cout<<p[r]-p[l-1]<<'\n';
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2){
			cha[i] = a[i]-a[i-1];
		}
	}
	sort(a+1,a+n+1);
	if(m>1e8){
		for(int i=n;i>=1;i--){
			if(m>=a[n]-a[i]){
				ans++,m-=(a[n]-a[i]);
			}
		}
		cout<<ans;
		return 0;
	}
	long long l = 1,r = n;
	while(l<=r){
		int mid = (l+r)>>1;
//		cout<<l<<' '<<mid<<' '<<r<<'\n';
		if(check(mid)) ans = mid,l = mid+1;
		else r = mid-1;
	}
	cout<<ans;
	return 0;
} 
