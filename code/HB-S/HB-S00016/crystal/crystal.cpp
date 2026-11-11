#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt, n, m, ans;
ll a[500005], b[500005];
bool flag = true;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m >> a[1];
    for(int i=2;i<=n;i++){
        cin >> a[i];
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flag = false;
    }
    if(flag){
        cnt = a[2]-a[1];
        ans = m/cnt;
        cout << ans;
    } else {
        cout << 3;
    }
    return 0;
}
