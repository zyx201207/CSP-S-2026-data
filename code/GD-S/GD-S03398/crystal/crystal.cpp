#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    if (n == 2){
        if (a[1] - a[0] <= m){
            cout << 2 << endl;
            return 0;
        }
        else {
            cout << 1 << endl;
            return 0;
        }
    }
    bool isab = true;
    long long diff = a[1] - a[0];
    for (int i = 2; i < n; i++){
        if (a[i] - a[i - 1] != diff){
            isab = false;
            break;
        }
    }
    int ans;
    if (isab){
        long long anx = 0;
        for(long long i = 1; i < n; i++){
            anx += diff * i;
            if (anx > m){
                cout << i << endl;
                return 0;
            }
        }
    }
    int start_index = 1;
    long long start_ans = 1;
    long long added = 0;
    while (added + start_index * (a[start_index] - a[start_index - 1]) <= m){
        added += start_index * (a[start_index] - a[start_index - 1]);
        start_ans++;
        start_index++;
    }
    ans = start_ans;
    for (int i = start_index; i < n; i++){
        int j = 1;
        int cans = 1;
        ll cur = 0;
        while(j <= i){
            if (cur + a[i] - a[i - j] <= m){
                cur += a[i] -a[i - j];
                cans++;
                j++;
            }
            else break;
        }
        if (cans > ans) ans = cans;
    }
    cout << ans << endl;
    return 0;
}