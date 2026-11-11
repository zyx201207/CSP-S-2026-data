#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll a[N],s,m,f[N];
ll maxdfs(ll n,ll c){
	if(c==m) return n;
	ll maxf=0;
	for(ll i=1;i<=s;i++){
		ll k=n&a[i];
		if(f[i]==0&&k>maxf){
			f[i]=1;
			maxf=k;
		}
	}
	return maxdfs(maxf,c+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>s>>m;
	for(ll i=1;i<=s;i++) scanf("%lld",&a[i]);
	ll maxn=0;
	for(ll i=1;i<=s;i++){
		memset(f,0,sizeof f);
		f[i]=1;
		ll x=maxdfs(a[i],1);
		if(x>maxn) maxn=x;
	}
	cout<<maxn;
	return 0;
}
