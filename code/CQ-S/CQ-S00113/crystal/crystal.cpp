#include <bits/stdc++.h>
#define llong long long
#define N 500005
using namespace std;

int n; llong m;
llong a[N], p[N];
int ans = 0;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; ++i) p[i] = p[i-1]+a[i];
    for(int i = 1; i <= n; ++i){
        int l = 1, r = i;
        while(l < r){
            int mid = (l+r)>>1;
            if((a[i]*(i-mid+1))-(p[i]-p[mid-1]) <= m)
                r = mid;
            else l = mid+1;
        }
        ans = max(ans, i-l+1);
    }
    cout << ans;
    return 0;
}
/*
Solve: 14:30
Fin:   
*/
