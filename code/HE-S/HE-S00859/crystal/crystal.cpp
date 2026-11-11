#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
uint8_t buf[1<<20],*p1,*p2;
const ll maxn=5e5+5;
ll n,m,a[maxn],d[maxn],sum[maxn],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+d[i];
	}
	ll l=1,r=2,cnt=0;
	while(l<=r&&l<=n&&r<=n){
		cnt+=d[r-1]*(r-l);
		if(cnt<=m){
			ans=max(ans,(r-l+1));
			r++;
		}else{
			while(cnt>m&&l<=n){
				cnt-=(sum[r]-sum[l-1]);
				l++;
			}
			ans=max(ans,(r-l+1));
			r++;
		}
	}
	cout<<ans;
	return 0;
}
