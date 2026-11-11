#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], l, r, num, sum = 0, ans;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    l = 1;
    r = 1;
    num = 1;
    ans = 1;
    while(l <= r && r <= n){
        if(sum < m){
            sum += (a[r + 1] - a[r]) * num;
            num ++;
            r ++;
        }else{
            l ++;
            num --;
            sum -= (a[r] - a[l - 1]);
        }
        if(sum <= m)ans = max(ans, num);
    }
    cout << ans;
    return 0;
}
