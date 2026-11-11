#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int a[N];
int n, m;
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a+1, a+1+n);
    int top, bot = 1, needm = 0, ans = 1; 
    for(top = 2; top <= n; top++){
        needm += ((top - bot)*(a[top]-a[top-1]));
        while(needm > m) {
            needm -= (a[top] - a[bot]);
            bot++;
        }
        ans = max(ans, top - bot+1);
    }
    cout << ans;
    return 0;
}
