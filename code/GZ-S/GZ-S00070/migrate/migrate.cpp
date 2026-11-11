// GZ-S00070 贵阳市白云区华师一学校 王舒越 
#include<bits/stdc++.h>
#define ll long long
#define MAXN 2000010
using namespace std;
ll c,t,n,d,a[MAXN],s[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll ans=0;
		for(ll i=1;i<=n;i++) cin>>a[i];
		d/=(a[2]-a[1]);
		ll cnt=0;
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				ll w=(a[j]-a[i])/d,x=j-i;
				if((a[j]-a[i])%d>0) w++;
				if(w==1) continue;
				ll sum=d-(x-(w-1)*d);
				if(sum==1) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
