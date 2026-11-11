#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, sum = 0;
    int ans = 0;
    for(int r = 1; r <= n; ++r){
        //先算答案
        ans = max(ans, r - l + 1);
        //然后加到下一个
        if(r == n) break;
        sum += (r - l + 1) * (a[r + 1] - a[r]);
        while(sum > m){
            sum -= a[r + 1] - a[l];
            ++l;
        }
    }
    cout << ans << endl;
    return 0;
}/*
T1 crystal 能量水晶
考虑从小到大双指针维护 水完了
即m次之后能有多少相同
烛焰水晶（喜）
*/