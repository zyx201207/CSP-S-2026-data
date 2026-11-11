#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[200001],ans;
void dfs(ll x,ll y,ll num){
	if(x==m){
		ans=max(ans,num);
		return ;
	}
	for(ll i=y;i<=n;i++){
		dfs(x+1,i+1,num&a[i]);
	}
}
void solve1(){
	dfs(0,1,INT_MAX);
	cout<<ans;
}
void solve2(){
	for(ll i=1;i<=n;i++) ans=max(ans,a[i]);
	cout<<ans;
}
void solve3(){
	ans=INT_MAX;
	for(ll i=1;i<=n;i++) ans&=a[i];
	cout<<ans;
}
void solve4(){
	for(ll i=1;i<=n;i++)
		for(ll j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
	cout<<ans;
}
void solve5(){
	sort(a+1,a+1+n);
	ans=INT_MAX;
	for(ll i=1;i<=m;i++) ans&=a[n-i+1];
	cout<<ans;
}
void solve6(){
	ll t[5];
	memset(t,0,sizeof(t));
	for(ll i=1;i<=n;i++) t[a[i]++];
	if(a[3]>=m) cout<<3;
	else if(a[3]+a[2]>=m) cout<<2;
	else if(a[3]+a[1]>=m) cout<<1;
	else cout<<0;
}
bool check(ll x){
	if(x==0) return 0;
	x++;
	while(x!=1){
		if(x%2==1) return 0;
		x/=2;
	}
	return 1;
}
void solve7(){
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n<=20) solve1();
	else if(m==1) solve2();
	else if(m==n) solve3();
	else if(m==2) solve4();
	else{
		bool b=0;
		for(ll i=1;i<=n;i++)
			if(a[i]!=i-1){
			 	b=1;
			 	break;
			}
		if(b==0) solve5();
		b=0;
		for(ll i=1;i<=n;i++)
			if(a[i]>=4){
			 	b=1;
			 	break;
			}
		if(b==0) solve6();
		b=0;
		for(ll i=1;i<=n;i++)
			if(check(a[i])==0){
				b=1;
				break;
			}
		if(b==0) solve7();
		else{
			sort(a+1,a+1+n);
			ans=INT_MAX;
			for(ll i=1;i<=m;i++) ans&=a[n-i+1];
			cout<<ans;
		}
	}
	return 0;
}

