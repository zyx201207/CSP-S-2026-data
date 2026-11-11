#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using ll=long long;
const ll INF=1e15;
ll m,n,a[N],mx=-INF,mn=INF,ans;
void solve1(){
	for(ll i=mn;i<=mx;i++){
		int id=upper_bound(a+1,a+n+1,i)-a;
		int l=id;	
		if(l>n) l--;
		if(a[l]>i) l--;
		ll nm=m,cnt=0;
		while(l>=1){
			if(i-a[l]<=nm){
				nm=nm-(i-a[l]);
				cnt++;
				l--;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
void solve2(){
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r)/2;
		if(((n-mid)+1)*1.0*((n-mid)*1.0/2)<=m){
			r=mid;
		}
		else l=mid+1;
	}
	cout<<n-l+1;
}
void solve3(){
	ll l=1,r=n,d=a[n]-a[n-1];
	while(l<r){
		ll mid=(l+r)/2;
		if(((n-mid)*d+d)*1.0*((n-mid)*1.0/2)<=m){
			r=mid;
		}
		else l=mid+1;
	}
	cout<<n-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int T1=1,T2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) T1=0;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) T2=0;
		mx=max(mx,a[i]),mn=min(mn,a[i]);
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	if(mn>=-100&&mx<=100){
		solve1();
		return 0;
	}
	if(T1){
		solve2();
		return 0;
	}
	if(T2){
		solve3();
		return 0;
	}
	solve1();
	return 0;
}
