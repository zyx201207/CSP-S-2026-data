#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 500005;
int n;
ll m;
ll a[N], b[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
        b[i] = b[i-1] + a[i];
    int ans = 1;
    for (int i = 2; i <= n; i++){
        int l = 1, r = i-1;
        while (l <= r){
            int mid = l+r >> 1;
            int len = i - mid;
            if (a[i] * len  - (b[i-1] - b[mid-1]) <= m) r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}
