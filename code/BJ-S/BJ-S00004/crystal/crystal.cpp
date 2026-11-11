#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 +9;
ll a[N];
ll n,m;
bool check(int l,int r,ll x){
    ll pluss = a[r + 1] - a[r];
    x += 1ll * (r - l + 1) * pluss;
    if(x > m) return 0;
    return 1;
}
void solved(){

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    ll mx = 1;
    ll need = 0;
    int r = 1;
    for(int i = 1;i <= n;i++){
        while(need <= m && r < n){
            if(check(i,r,need)){
                need += (a[r + 1] - a[r]) * (r - i + 1);
                r++;
                mx = max(mx,1ll * r - i + 1);
            }
            else break;
        }
        need -= (a[r] - a[i]);

    }
    cout << mx <<endl;
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solved();
    }
    return 0;
}
