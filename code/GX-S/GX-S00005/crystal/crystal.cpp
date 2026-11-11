#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[500086] = {},ma = -1;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        int p = m,an = 1;
        for(int j = 1;j < i;j++){
            if(p < a[i] - a[j])break;
            else{
                an++;
                p -= a[i] - a[j];
            }
        }
        ma = max(an,ma);
    }
    cout << ma;
    return 0;
}
