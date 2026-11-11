#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
inline bool f(long long x){
	for(int i=x;i<=n;i++){
		if(b[i]-b[i-x]+m>=a[i]*x) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int l=1,r=n,md;
	while(l<=r){
		md=(l+r)>>1;
		if(f(md)) l=md+1;
		else r=md-1;
	}
	cout<<l-1;
	return 0;
}
