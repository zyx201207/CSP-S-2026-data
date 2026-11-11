#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool cmp(ll x,ll y){
    return x > y;
}
ll n,m,cnt,zm;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<ll> a(n);
    bool f = true;
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
        if(i == 1) zm = a[1] - a[0];
        if(i > 1 && zm != a[i] - a[i - 1]) f = false;
    }if(f){
        cout << min(n,m / zm);
        return 0;
    }
    sort(a.begin(),a.end(),cmp);
    for(int i = 1;i <= n - 1;i++){
        int j = i + 1,m_ = m;
        while(j <= n&&m_ > 0){
            if(m_ >= a[i] - a[j]) m_ -= (a[i] - a[j++]);
            else break;
        }cnt = max(cnt,j - i);
    }cout << cnt;
}
