#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m, a[500005];
    cin >> n >> m;
    for(int i = 1; i <=n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long pre[500005];
    pre[0] = 0;
    pre[1] = 0;
    for(int i = 2; i <= n; i++){
        pre[i] = pre[i - 1] + (a[i] - a[i - 1]) * (i-1);
    }
    if(pre[n] <= m){
        cout << n << endl;
        return 0;
    }
    long long maxn = LLONG_MIN;
    for(int l = 1, r = 1; l <= n;l++){
        while(pre[r + 1] - pre[l] - (a[r+1] - a[l])*(l - 1) <= m && r + 1 <= n){
            r++;
        }
        if(pre[r] - pre[l] - (a[r] - a[l]) * (l - 1) <= m && a[l] < a[r] && r <= n){
            maxn = max(maxn,  1LL * (r - l + 1));
            r++;
        }
    }
    if(maxn < 0){
        int cnt = 1, maxlen = -1;
        for(int i = 2; i <= n; i++){
            if(a[i] == a[i - 1]) cnt++;
            else{
                maxlen = max(maxlen, cnt);
                cnt = 1;
            }
        }
        cout << maxlen << endl;
        return 0;
    }
    cout << maxn << endl;
    return 0;
}
