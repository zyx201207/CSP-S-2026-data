#include<bits/stdc++.h>
using namespace std;
using ll= long long;
const int maxn=5e5+5;
ll a[maxn],m,sum[maxn];
int n;
bool check(int len){
	ll mi=m+1;
	for(int l=1,r=l+len-1;r<=n;l++,r++){
		mi=min(mi,a[r]*len-(sum[r]-sum[l-1]));
	}
	return mi<=m;
}
int solve(){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	cout<<solve();
	return 0;
}

