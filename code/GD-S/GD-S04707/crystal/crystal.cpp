#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const N=5e5+7;
ll a[N],x[N],n,m;
bool check(int k){
	for(int i=k;i<=n;i++){
		ll q=x[i]-x[i-k];
		if(a[i]*k-q<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) x[i]=x[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
