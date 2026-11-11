#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=5e5+5;
ll n,m,a[N],s[N];

bool check(int mid){
	for(int i=mid;i<=n;++i){
		if(a[i]*mid-(s[i]-s[i-mid])<=m){
			return true;
		}
	}
	return false;
}

int find_max(int l,int r){
	while(l<r){
		int mid=l+((r-l+1)>>1);
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	return l;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	cout<<find_max(1,n)<<'\n';
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	while(t--) solve();

	return 0;
}