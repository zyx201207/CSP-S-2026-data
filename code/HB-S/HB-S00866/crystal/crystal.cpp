#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5+7;
int a[maxn];
int n,m;
int nd[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    nd[1] = 0;
    for (int i = 2;i <= n;i++) nd[i] = nd[i-1]+(a[i]-a[i-1])*(i-1);
    for (int i = n;i >= 1;i--){
        if (m >= nd[i]){
            cout << i;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
