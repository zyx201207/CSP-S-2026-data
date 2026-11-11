#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define fileio(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define mems(x,v) memset(x,v,sizeof(x))
using namespace std;
namespace BaoTx{
	using ll=long long;
	const int N=5e5+5;
	ll n,m;
	ll a[N];
	ll s[N];
	void main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ll l=1,r=i,now=i;
			while(l<=r){
				ll mid=(l+r)/2;
				if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
					now=mid;
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			ans=max(ans,i-now+1);
		}
		cout<<ans;
	}
}
int main(){
	fileio(crystal);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	BaoTx::main();
	return 0;
}// 1449