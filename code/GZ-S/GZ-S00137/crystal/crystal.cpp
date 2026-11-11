//GZ-S00137 ³Â³½ 
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define ll long long
ll a[N];
void solve(){
	ll n,m; 
	cin >>n>>m;
	for (int i = 1;i <= n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	ll l=1,sum=0,ans=0;
	for (int i = 1;i <= n;i++){
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m){
			sum-=a[i]-a[l++];
		}
		ans=max(ans,i-l+1);
	}
	cout <<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	int T=1;
	//cin >>T;
	while(T--){
		solve();
	}
	return 0;
}
