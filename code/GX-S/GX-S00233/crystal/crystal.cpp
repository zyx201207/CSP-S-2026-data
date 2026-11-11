#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    int n, m, a[20001000], cnt = 0, sum = 0;
    cin >> n >> m;
    for (int i = 1;i <= n; i ++){
        cin >> a[i];
        if (a[i] <= a[i + 1]) cnt += a[i];
        else cnt += i - 1;
            if (cnt < m){
        sum += 1;
        cnt += i - 1;
        } else {
        if (m - cnt > 0){
        for (int i = 1; i <= m - cnt; i ++){
        sum = sum - 1;
            }
        }
    }
}

    cout << sum;
    return 0;
}
