#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll pls=1e12;

void solve(){
    ll n,m;cin>>n>>m;
    vector<ll>a(n+1,0),pre(n+1,0);
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    for (int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
    
    // for (int i=0; i<=n; i++){
    //     cout<<pre[i]<<" ";
    // }cout<<endl;
    // for (int i=0; i<=n; i++){
    //     cout<<a[i]<<" ";
    // }cout<<endl;

    function<bool(int)> check = [&](int x){
        for (int i=x; i<=n; i++){
            // cout << i <<" "<< x <<" "<< a[i]*x-(pre[i]-pre[i-x])<<":::"<<a[i]<<" "<<pre[i]<<" "<<pre[i-x]<<"\n";
            if (a[i]*x-(pre[i]-pre[i-x])<=m) return true;
        }
        return false;
    };

    int l=1, r=n, ans=0;
    while (l<=r){
        int mid=(l+r)/2;
        if (check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout << r << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve();
    return 0;
}