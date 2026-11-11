#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,maxn,ans=1,a[N];
bool v[N];
struct node{
	ll n,c;
}b[N];
ll trans_2(ll x){
	string s;
	ll ans=0;
	while(x){
		s+=(x%2)+'0';
		x/=2;
	}
	for(ll i=0;i<ll(s.size());i++) {
		if(s[i]=='1') ans++;
	}
	return ans;
}
bool cmp(const node &x, const node &y){
	return x.c>y.c;
}
/*void dfs(ll d,ll m,ll cur){
	if(cur==m){
		maxn=max(maxn,m);
		return ;
	}
	for(ll i=1+d;i<=n;i++){
		if(m==0) dfs(i,a[i],cur+1);
		else dfs(i,m&a[i],cur+1);
	}
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	//if(n<=20) {dfs(0,0,0); cout<<maxn;}
	if(m==1){
		for(ll i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
	}else if(m==n){
		ans=a[1];
		for(ll i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
	}else if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}else{
		sort(a+1,a+n+1,greater<ll>());
		ans=a[1];
		for(ll i=2;i<=m;i++) ans&=a[i];
		cout<<ans;
	}
	return 0;
}
