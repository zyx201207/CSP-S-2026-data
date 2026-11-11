#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
constexpr int ms1 = 5e5 + 5;
constexpr int ms2 = 3e5 + 5;
using namespace std;

int a[ms1],cpy[ms1];
int mn1[ms2],mn2[ms2];
int ans[ms2];
int n,m;

void solve(){
    int l,r;

    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            cpy[i] = 0;
        }
        for(int i = 1;i <= m;i++){
            mn2[i] = 0;
        }
        r = 0;
        for(int i = k;i <= n;i++){
            if(mn2[a[i]] != 0 && mn2[a[i]] <= r && cpy[mn2[a[i]]] == a[i]){
                r = mn2[a[i]];
            }
            else{
                r++;
                cpy[r] = a[i];
                mn2[a[i]] = r;
            }
        }
        for(int i = 1;i <= r;i++){
            ans[cpy[i]]++;
        }
    }

    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        cin >> a[i];
        //mn1[a[i]] = (mn1[a[i]] == 0 ? i : mn1[a[i]]);
    }

    solve();
    return 0;
}
