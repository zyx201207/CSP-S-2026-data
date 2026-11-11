#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m, l, r;
int a[N];
bool flag = true, flag1 = true;

bool check(int mid){
    int x = a[mid];
    int sum = 0;
    for(int i = mid - 1; i >= 1; i--){
        int cost = x - a[i];
        sum += cost;
    }
    return sum <= m;
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != i) flag = false;
    }
    int d = a[2] - a[1];
    for(int i = 3; i <= n; i++){
        if(a[i] - a[i - 1] != d){
            flag1 = false;
        }
    }
    sort(a + 1, a + n + 1);
    if(flag){
        int res = 0;
        for(int i = n - 1; i >= 1; i--){
            int cost = n - i;
            if(m >= cost){
                m -= cost;
                res++;
            }
        }
        cout << res + 1;
        return 0;
    }
    if(flag1){
        int res = 0;
        for(int i = n - 1; i >= 1; i--){
            int cost = a[n] - a[i];
            if(m >= cost){
                m -= cost;
                res++;
            }
        }
        cout << res + 1;
        return 0;
    }
    if(n <= 5000){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int x = a[i];
            int cnt = 1;
            int cur = m;
            for(int j = i - 1; j >= 1; j--){
                int cost = x - a[j];
                if(cur >= cost){
                    cur -= cost;
                    cnt++;
                }
                else break;
            }
            ans = max(ans, cnt);
        }
        cout << ans;
        return 0;
    }
    int ans = 0;
    l = 1; r = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
