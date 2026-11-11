#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =5e5+10;

int n;
ll m;
ll a[N];
ll cf[N];
ll dp[N];
ll cfs[N];

bool check(ll mid){
	
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>mid){
			return true;
		}
		else sum+=mid-a[i];
		
		if(sum>m) return false;
	}
	return true;
}
ll low(ll mid){
	
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>mid){
			return i-1;	
		}
		else sum+=mid-a[i];
		
		if(sum>m) return i-1;
	}
	return n;
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}sort(a+1,a+n+1);
	
	
	ll l=1,r=a[n];
	ll deq=-1;
	while(l<=r){
		
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else r=mid-1;
		deq=max(deq,low(mid));
	}cout<<deq;
	return 0;
}

