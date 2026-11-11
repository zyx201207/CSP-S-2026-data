#include<bits/stdc++.h>
using namespace std;//二分答案 
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],pre[N],mina=1e18,maxa=-1e18;
inline int count(ll wz){
	ll cnt=0,m1=m,nl=a[wz];
	for(ll i=wz-1;i>=1;i--){//贪心计算能改变多少水晶 
		m1=m1-(nl-a[i]);
		if(m1>=0)cnt++;
		else break;
	}
	return cnt;
}
inline bool check(ll num){//遍历出从哪里开始改变水晶 
	ll now=0,res=0;
	for(ll i=2;i<n;i++){
		now=count(i);
		if(now>res)res=now;
	}
	return res>=num; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxa) maxa=a[i];
		if(a[i]<mina) mina=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]-a[i-1];
	}
	ll l=1,r=n,mid;//二分水晶数量 
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
