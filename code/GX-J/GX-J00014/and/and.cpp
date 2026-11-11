#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector <int> a(n+5);
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end(),greater <int>());
    if (m == 1){
        cout << a[0];
        return 0;
    }
    if (m == 2){
        cout << (a[0] & a[1]);
        return 0;
    }
    long long ans = a[0];
    for (int i=1;i<=m-1;i++) ans &= a[i];
    cout << ans;
    return 0;
}
