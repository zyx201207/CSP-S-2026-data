#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans = -1;
int AND(int x, int y){
    int s1[35], s2[35], s[35];
    int l1 = 0, l2 = 0, l = 0;
    while(x > 0){
        s1[l1] = x % 2;
        x /= 2;
        l1++;
    }
    while(y > 0){
        s2[l2] = y % 2;
        y /= 2;
        l2++;
    }
    for(int i = 0; i < min(l1, l2); i++){
        if(s1[i] == 1 && s2[i] == 1){
            s[i] = 1;
        }
        else{
            s[i] = 0;
        }
        l++;
    }
    int t = 0, p = 1;
    for(int i = 0; i < l; i++){
        t += s[i] * p;
        p *= 2;
    }
    return t;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(m == 1){
        for(int i = 1; i <= n; i++){
            ans = max(ans, AND(a[i], 1111111111));
        }
        cout << ans;
        return 0;
    }
    else if(m == n){
        ans = a[1];
        for(int i = 2; i <= n; i++){
            ans = AND(ans, a[i]);
        }
        cout << ans;
        return 0;
    }
    else{
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                ans = max(ans, AND(a[i], a[j]));
            }
        }
        cout << ans;
        return 0;
    }
}
