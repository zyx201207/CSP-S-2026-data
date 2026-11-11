//兰玉昊 GZ-S00043 观山湖中学
#include<bits/stdc++.h>
using namespace std;

int n, ma = 1, flag = 1;
long long m, a[500050], mi = 1e12+10;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    cin >> m;
    cin >> a[1] >> a[2];
    for(int i = 3;i <= n;i++){
        cin >> a[i];
        if(a[i] - a[i-1] != a[i-1] - a[i-2]) flag = 0;
    }
    if(flag){
        m -= m % (a[2] - a[1]);
        m /= (a[2] - a[1]);
        int i = 1;
        for(;m >= 0;i++){
            m -= i;
        }
        cout << min(i-1, n);
        return 0;
    }
    sort(a+1, a+1+n);
    int l, r;
    for(l = 1;l < n;l++){
        long long val = 0;
        for(r = l + 1;r <= n;r++){
            long long v = val + ((a[r] - a[r-1]) * (r - l));
            if(v > m) break;
            else val = v;
        }
        ma = max(ma, (r - l));
    }
    cout << ma;
    //那五个测试点我真没招了，李老师你公开处刑就公开处刑吧，喷轻点
    return 0;
}
