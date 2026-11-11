#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5,M=5e3+3;
ll a[N],m;
int n;
bool check(int x){
	ll nw=0;
	for(int i=1;i<x;++i)nw+=a[x]-a[i];
	if(nw<=m)return 1;
	for(int i=x+1;i<=n;++i){
		nw=nw+(a[i]-a[i-1])*(x-1)-(a[i-1]-a[i-x]);
		if(nw<=m)return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,mid,ans=1;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

