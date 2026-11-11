#include<bits/stdc++.h>
using namespace std;
map<int, char> a;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n; cin >> n;
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        int x; char y;
        cin >> x >> y;
        a[cnt] = y; a[cnt + x - 1] = y;
        cnt += x;
    }
    char bzw = a[1];
    for(int i = 1; i < cnt; i++){
        if(a[i] != bzw && a[i] >= 'a' && a[i] <= 'z'){
            bzw = a[i];
        }
        a[i] = bzw;
    }
    int ans = 0;
    for(int i = 1; i < cnt / 2; i++){
        if(a[i] != a[cnt - i]) ans++;
    }
    cout << ans;
}
