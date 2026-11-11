#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n,m,a[N],ma = -1e9,mi = 1e9;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        ma = max(a[i], ma);
        mi = min(a[i], mi);
    }
    cout << ma - mi;
    return 0;
}
