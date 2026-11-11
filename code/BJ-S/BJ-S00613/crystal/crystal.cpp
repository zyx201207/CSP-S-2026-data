#include <bits/stdc++.h>
using namespace std;
const int MAXn = 500010;
int n, m, a[MAXn], mid, realmid;
int dfs(int l, int r){
    if(l == r && r == mid){
        return mid;
    }
    mid = (l + r) / 2;
    if(mid > realmid){
        return dfs(l, mid - 1);
    }else if(mid < realmid){
        return dfs(mid + 1, r);
    }else{
        return realmid;
    }
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    realmid = (abs(a[n]) - abs(a[1])) / 2;
    realmid = dfs(1, n);
    while(true){
        int sum = 0, ans = 0, j = 1;
        for(int k = j; k <= n; k++){
            if(a[k] <= realmid){
                sum += realmid - a[k];
                ans++;
            }
        }
        if(m >= sum){
            cout << ans;
            break;
        }else{
            j++;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
