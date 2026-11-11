#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define in inline
const ll maxn=5e5+5;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
ll a[maxn];
ll sum[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	ll l=1,r=1;
	ll ans=	0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	while(r!=n){
		if((r-l)*a[r]-sum[r-1]+sum[l-1]<=m){
			ans=max(ans,r-l+1);
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
