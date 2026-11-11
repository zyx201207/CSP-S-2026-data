#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a[200005], ans;
bool cmp(ll a, ll b){
    return a>b;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, cmp);
    ans = a[m];
    for(int i=1;i<=m;i++){
        ans &= a[m];
    }
    cout << ans;
    return 0;
}
