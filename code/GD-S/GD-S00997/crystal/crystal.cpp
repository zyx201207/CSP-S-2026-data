#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10;
long long n,m,a[N],p[N],ans;
int check(long long mid){
	for(int i=mid;i<=n;i++){
		if(mid*a[i]-(p[i]-p[i-mid])<=m)return 1;
	}
	return 0;
}
void solve(){
	if(1){
		long long l=0,r=n;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			p[i]=p[i-1]+a[i];
		} 
		while(l<=r){
			long long mid=(l+r)/2;
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<ans;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	solve();
	return 0;
}
