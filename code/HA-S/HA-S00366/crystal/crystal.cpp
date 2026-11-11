#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll x;cin>>x;return x;}
const int N=5e5+10;
ll n,m,ans,a[N],sum[N];
bool check(ll l,ll r){
	return sum[r]-sum[l]-(a[r]-a[l])*(l-1)<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	for(int i=1;i<=n;i++){
		ll l=1,r=i,mid;
		while(l+1<r){
			mid=(l+r)/2;
			if(check(mid,i)) r=mid;
			else l=mid;
		}
		if(check(l,i)) ans=max(ans,i-l+1);
		else ans=max(ans,i-r+1); 
	}
	cout<<ans<<'\n';
	return 0;
} 
