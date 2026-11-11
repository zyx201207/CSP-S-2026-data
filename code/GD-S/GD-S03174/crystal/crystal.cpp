#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N];
ll sum;
bool check(ll x){
	sum=0;
	bool ff=0;
	for(ll i=2;i<=n;i++){
		sum=sum+min(x,i-1)*(a[i]-a[i-1]);
		if(i>=x+1)sum=sum-(a[i]-a[i-x]);
		if(i>=x&&sum<=m)ff=1;
	}
	return ff;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
} 
