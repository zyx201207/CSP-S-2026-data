#include<bits/stdc++.h>
using namespace std;
long long h[500005],a[500005],n,m,l,r,mid;
bool check(int t){
	long long ret=9223372036854775807,bj;
	for(int i=t;i<=n;i++){
		ret=min(t*a[i]-(h[i]-h[i-t-1]),ret);
	}
	return ret<=m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n); 
	for(int i=1;i<=n;i++) h[i]=h[i-1]+a[i];
	r=n;l=1;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid) && !check(mid+1)){
			cout<<mid;
			return 0;
		}
		else if(check(mid)){
			l=mid+1;
		}else {
			r=mid-1;
		}
	}
}
// 
