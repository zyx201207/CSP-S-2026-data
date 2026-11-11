#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[200005];
ll ans=0;
int de(int x,int y){
	string s="",f="",g="";
	while(x!=0){
		if(x%2==1){
			s="1"+s;
		}else{
			s="0"+s;
		}
		x/=2;
	}
	while(y!=0){
		if(y%2==1){
			f="1"+f;
		}else{
			f="0"+f;
		}
		y/=2;
	}
	int l=s.size(),r=f.size();
	s=" "+s;
	f=" "+f;
	while(1){
		if(s[l]==f[r]&&s[l]=='1'){
			g="1"+g;
		}else{
			g="0"+g;
		}
		l--;
		r--;
		if(l==0||r==0){
			break;
		}
	}
	ll u=1,b=0;
	for(ll i=g.size()-1;i>=0;i--){
		if(g[i]=='1'){
			b+=u;
		}
		u*=2;
	}
	return b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n-m+1;i++){
		ll sum=de(a[i],a[i+1]);
		for(ll j=i+2;j<=i+m-1;j++){
			sum=de(sum,a[j]);
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
