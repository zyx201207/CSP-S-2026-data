#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int n,m,maxn,a[N],sum[N];
void sol(){
    int ans = 0,cnt = 0,dis = a[2]-a[1];
    while (ans < m){
        cnt++;
        ans += dis*cnt;
        if (ans > m){
            ans -= dis*cnt;
            cnt--;
            break;
        }
        if (cnt == n-1) break;
    }
    cnt++;
    cout << cnt;
    return;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    bool flagA = 1,flagB = 1;
    for (int i = 1;i <= n;i++){
        if (a[i] != i) flagA = 0;
    }
    for (int i = 1;i <= n-2;i++){
        if (a[i+1]-a[i] != a[i+2]-a[i+1]) flagB = 0;
    }
    if (flagA || flagB){
        sol();
        return 0;
    }
    for (int i = 1;i <= n;i++){
        int ans = 0,s = 0;
        for (int j = i;j >= 2;j--){
            s += (a[i] - a[j-1]);
            ans++;
            if (s > m) break;
            if (s == m){
                ans++;
                break;
            }
        }
        maxn = max(ans,maxn);
    }
    cout << maxn;
    return 0;
}
