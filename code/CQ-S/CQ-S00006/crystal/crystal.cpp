#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m,avg[N],f[N],a[N],sum,b[N];
bool check(ll x){
	for(int i=1;i<=n;i++){
		b[i]=abs(avg[x]-a[i]);
	}
	sort(b+1,b+n+1);
	ll ans=0;
	for(int i=1;i<=x;i++){
		ans+=b[i];
	} 
	return ans<=m;
}
int main(){
	//rp++
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum+=abs(a[i]);
	}
	cout<<sum<<' '<<m<<endl; 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		avg[i]=f[i]/i;
	}
	ll L=1,R=n,ans=L;
	while(L<=R){
		ll mid=L+R>>1;
		if(check(mid)){
			ans=mid;
			L=mid+1;
		}else R=mid-1;
	}
	cout<<ans;
	return 0;
}
