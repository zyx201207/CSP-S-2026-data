#include<bits/stdc++.h>
using namespace std;
long long a[500010], b[500010], m, ans;
bool check(int x, int i){
    return (a[i]*(i-x+1)-(b[x]-b[i+1])) <= m;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i = n; i >= 1; i--){
        b[i] = b[i+1]+a[i];
    }
    for (int i = 1; i <= n; i++){
        int l = 1, r = i;
        long long cnt = i+1;
        while (l <= r){
            int mid = (l+r)/2;
            if (check(mid, i)){
                cnt = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        ans = max(ans, i-cnt+1);
    }
    cout << ans;
    return 0;
}
