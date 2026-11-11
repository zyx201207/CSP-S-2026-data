#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 86;
ll n,m,a[N],ans;
ll f(ll x){
    ll M = m,cnt = 0;
    for(int i = x;i > 0;i--){
        if(M < a[x] - a[i]) return cnt;
        M -= a[x] - a[i];
        cnt++;
    }
    return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a + 1,a + n + 1);
    ll l = 1,r = n;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(f(mid) >= ans) ans = f(mid),l = mid + 1;
        else r = mid - 1;
    }
    cout<<ans;
	return 0;
}