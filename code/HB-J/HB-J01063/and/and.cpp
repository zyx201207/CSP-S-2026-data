#include<bits/stdc++.h>
#define maxN 200010
#define maxA 1<<30+10

using namespace std;
bool num[maxN][31], waste[maxN] = {};
unsigned int m, n, a[maxN], ans = 0, cnt[31] = {};

void devide(){
    for(int i = 1; i <= n; i ++){
        int temp = a[i];
        for(int j = 1; j <= 30; j ++){
            num[i][j] = temp & 1;
            if(temp & 1){
                cnt[j] ++;
            }
            temp >>= 1;
        }
    }
    return;
}

void solve(){
    for(int i = 30; i >= 1; i --){
        if(cnt[i] >= m){
            ans += (1 << i) >> 1;
            for(int j = 1; j <= n; j ++){
                if(waste[j]){
                    continue;
                }
                if(!num[j][i]){
                    waste[j] = 1;
                    for(int k = 1;k <= 30;k ++){
                        cnt[k] -= num[j][k];
                    }
                }
            }
        }
    }
    return;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    devide();

    solve();

    cout << ans;

    return 0;
}
