#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n;
ll m;
ll a[N];
bool cmp(ll a, ll b){
    return a < b;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1, cmp);
    a[n + 1] = 1e18;
    int ans = 1;
    ll v = 0;
    for(int l = 1, r = 0; l <= n; l++){
        v -= a[r] - a[l - 1];
        while(l < r && v > m){
            l++;
            v -= a[r] - a[l - 1];
        }
        while(r <= n && v + (a[r + 1] - a[r]) * (r - l + 1) <= m){
            v += (a[r + 1] - a[r]) * (r - l + 1);
            r++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
