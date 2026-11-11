#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e6 + 10;

int n;
ll m;
ll a[N], pre[N];

bool check(int l, int r){
    ll w = a[r] * (r - l + 1) + pre[r] - pre[l - 1];
    return w <= m;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >>n>>m;
    for(int i = 1; i <= n; i ++){
        cin >>a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i ++) pre[i] = pre[i - 1] - a[i];
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        int l = 1, r = i, res = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid, i)) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - res + 1);
    }
    cout <<ans;

    return 0;
}