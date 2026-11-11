#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+7;
int n,m;
map <int,int> mp;
int mi[37];//2^x
int a[maxn];
int maxx = 0;
int y;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    mi[0] = 1;
    for (int i = 1;i <= 30;i++) mi[i] = mi[i-1]*2;
    cin >> n >> m;
    bool flag = 1;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        if (i != 1 && a[i] != a[i-1]) flag = 0;
        maxx = max(maxx,a[i]);
        if (i == 1) y = a[i];
        else y = y & a[i];
        int sum = 0;
        for (int i = 30;i >= 0;i--) if (sum+mi[i] <= a[i]) sum += a[i],mp[mi[i]]++;
    }
    if (flag){
        cout << 1;
        return 0;
    }
    if (m == 1){
        cout << maxx;
        return 0;
    }
    if (m == n){
        cout << y;
        return 0;
    }
    int maxxx = 0;
    if (m == 2){
        for (int i = 1;i <= n;i++) for (int j = i+1;j <= n;j++) maxxx = max(maxxx,a[i] & a[j]);
        cout << maxxx;
        return 0;
    }
    int summ = 0;
    for (int i = 1;i <= 30;i++) if (mp[mi[i]] >= m) summ = max(summ,mi[i]);
    cout << summ;
    return 0;
}
