#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[500005],maxn = 2;
int main(){
	int f = 1;
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=n;i++) {
	cin>>a[i];if(a[i]!=i) f = 0;}
	if(f&&m>n) { cout<<n;return 0;}
    sort(a+1,a+n+1);
    for(ll i = n;i>=1;i--){
        ll ans = 0;
        for(int j = 1;j<=i;j++){
            ans+=a[j];
        }
        ans+=m;
        if(ans/i>a[i]) maxn = max(i,maxn);
        else if(ans/i==a[i]) maxn = max(i,maxn);
    }
    return 0;
}
