#include<bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
typedef long long ll;
const int N = 5e5+6;
ll a[N];
ll n,m;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll sum = 0;
    int ans = 0;
    sum = 0;
    for(int r = n,l=n;r;r--){
        if(r!= n) sum = max(0ll,sum - (r+1-l) * (a[r+1] - a[r]));
        // cout<<sum<<' '<<r<<' '<<l<<' ';
        while(l>1&&sum + a[r] - a[l-1] <= m) {l--;sum += a[r] -a[l];}
        // cout<<sum<<' '<<r<<' '<<l<<'\n';
        ans = max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}//100pts