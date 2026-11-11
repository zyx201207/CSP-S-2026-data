#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int Maxn = 2e5 + 5;
bool dig[Maxn][40], sel[Maxn];
int a[Maxn];
void indig(int x, int f){
    int cnt = 0;
    while(x){
        dig[f][cnt] = x % 2;
        x /= 2;
        cnt++;
    }
    return;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sel[i] = true;
    }
    for(int i = 1; i <= n; i++){
        indig(a[i], i);
    }
    for(int i = 31; i >= 0; i--){
        int cnt = 0;
        for(int j = 1; j<=n; j++){
            if(sel[j])
                cnt += dig[j][i];
        }
        if(cnt >= m){
            for(int j = 1; j<=n; j++){
                if(sel[j] && (dig[j][i] == 0))
                    sel[j] = 0;
            }
        }
    }
    int ans = 2147483647;
    for(int i = 1; i <= n; i++){
        if(sel[i]){
            ans &= a[i];
        }
    }
    cout << ans;
    return 0;
}
/*
AFO?
Not this Year!!!
展示诈骗水平：
//freopen("and.in", "r", stdin);
//cout << ans
//int mian
//return 0;
求上迷惑行为大赏 pls
*/
