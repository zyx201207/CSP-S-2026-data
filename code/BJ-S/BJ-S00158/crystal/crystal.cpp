#include <bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
int n, m, a[N];
bool check(int x){
    int sum = 0;
    for(int i = 1; i <= x; i++){
        sum += a[x] - a[i];
    }
    return sum <= m;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    int answer = 1;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)){
            l = mid + 1;
            answer = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}
