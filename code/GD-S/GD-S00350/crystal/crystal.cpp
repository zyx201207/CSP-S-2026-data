#include<bits/stdc++.h>
using namespace std;
using ll=long long; 
ll n,m,a[500005];
__int128 c[500005];
bool check(ll x){
	for(ll j=x;j<=n;j++){
		__int128 sum=c[j]-c[j-x];
		if((__int128)a[j]*x - sum <=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);//别忘了freopen 
	freopen("crystal.out","w",stdout);//别忘了freopen 
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	ll l=1,r=n,mid,ans=0;
	while(r>l){
		mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}
//15：28结束T1

/*
洛谷1404759 rp++
我想上电视
使用了二分+前缀和
python造个数据，感觉可以 
*/ 
