#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,maxn=1,a[500005],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(ll i=1;i<n;i++){
		ll cnt=1,j=i,s=m;
		while(j!=0){
			j--;
			ll x=a[i]-a[j];
			s-=x;
			if(s>=0) cnt++;
			else break;
}
		maxn=max(maxn,cnt);
}
	cout<<maxn;
	return 0;
} 
