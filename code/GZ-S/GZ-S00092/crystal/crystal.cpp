//GZ-S00092,罗翊航，贵阳市第一中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll CNT = 5e5+5;
ll n ,ans;bool flag=1 , cs;
ll m , a[CNT] , sum[CNT];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}cs=a[2]-a[1];
	for(int i = 2; i <= n; i++){
		if(a[i]-a[i - 1]!=cs)flag=0;
	}
	if(flag){
		for(ll i = 2; i <= n; i++){
			ll cnt = (a[i]*i-a[1]*i)/2;
			if(cnt<=m)ans=max(ans,i);
		}
		cout << ans;return 0;
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1]+a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i - 1; j >= 1; j--){
			ll k = i-j+1;
			if(a[i]*k-(sum[i]-sum[j-1])<=m)ans = max(ans , k);
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
