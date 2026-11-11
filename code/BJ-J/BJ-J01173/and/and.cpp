#include<bits/stdc++.h>
using namespace std;
long long n, m, a[1100000], ans, b[1100000], x, f;
/*void abc(int x, long long s, long long z){
    if(x == m){
        ans = max(ans, s);
    }else{
        for(int i = z; i <= n; i++){
            long long y = s;
            if(x == 0) s = a[i];
            else s = (s & a[i]);
            abc(x + 1, s, i + 1);
            s = y;
            //cout << a[i] << " ";
        }
    }
    //cout << endl;
}*/
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] >= 4) f = 1;
    }
    sort(a + 1, a + 1 + n);
    if(m == 1){
        cout << a[n];
        return 0;
    }
    if(m == 2){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                ans = max(ans, (a[i] & a[j]));
            }
        }
        cout << ans;
        return 0;
    }
    /*for(int i = 1; i <= n; i++){
        if(a[i] % 2 == 1){
            x++;
            b[x] = a[i];
        }
    }*/
    if(!f){
        cout << 4;
        return 0;
    }
    ans = a[n];
    for(int i = n - 1; i > n - m; i--){
        ans = (ans & a[i]);
    }
    cout << ans;
    return 0;
}
