#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+10;
ll a[N];
ll n,m;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(nullptr),ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i<=n;i++) {
            cin>> a[i];
    }
    sort(a+1,a+1+n);
    ll use = 0;
    for(int i = 1; i<=n;i++){
        use += (a[i]-a[i-1]) * 1LL *(i-1);
        if(use > m){
            cout << i-1;
            return 0;
        }
    }
    cout << n;
    return 0;

}


