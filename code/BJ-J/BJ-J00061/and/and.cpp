#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n+5];
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int ans = a[1];
    for(int i = 1;i<=m;i++){
        ans&=a[i];
    }
    cout << ans;
    return 0;
}
