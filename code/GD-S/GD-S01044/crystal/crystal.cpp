#include <bits/stdc++.h> 
using namespace std;

using ll =long long;
const int N=5e5+5;
ll n,m,a[N],s[N];
bool check(int mid){
	ll mi=LLONG_MAX;
	for(int i=mid;i<=n;i++){
		mi=min(mi,a[i]*mid-s[i]+s[i-mid]);
	}
	return mi<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
