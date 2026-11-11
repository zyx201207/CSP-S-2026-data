#include<bits/stdc++.h>
#define maxN 500050

using namespace std;

long long n, m, a[maxN], ans = 1;

void solve(){
    long long cost, result, pre;
    for(int i = 2;i <= n; i ++){
        cost = 0, result = 1, pre = 1;
        while(pre < i){
            if(cost + (a[i] - a[i - pre]) <= m){
                cost += (a[i] - a[i - pre]);
                pre ++;
                result ++;
            }else{
                break;
            }
        }
        ans = max(result, ans);
    }
    return;
}

int main(){
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    solve();

    cout << ans;

    return 0;
}
