#include <bits/stdc++.h>
using namespace std;

int a[200005];

int count1(int x){
    int cnt = 0;
    while(x > 0){
        if(x % 2)cnt++;
        x /= 2;
    }
    return cnt;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)cin >> a[i];

    int ans = a[0];
    if(m == 1){
        for(int i = 1; i < m; i++)ans = max(a[i] & 1);
    }

    cout << ans;

    return 0;
}
