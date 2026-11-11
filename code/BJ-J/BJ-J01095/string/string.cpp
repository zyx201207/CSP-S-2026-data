#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e6 + 5;
int a[maxn];
char c[maxn];
char s[maxn];

int f(){
    int n;
    cin >> n;

    int len = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i] >> c[i];
    }

    if (n == 1){
        return 0;
    }else if(n == 2){
        if(c[1] == c[2]){
            return 0;
        }else{
            return min(a[1], a[2]);
        }
    }

    int l = 1, r = n, ans = 0;
    while (l < r){
        if (c[l] != c[r]) ans += min(a[l], a[r]);
        if (a[l] > a[r]){
            a[l] -= a[r];
            r --;
        }else if (a[l] < a[r]){
            a[r] -= a[l];
            l ++;
        }else{
            l ++; r --;
        }
    }
    return ans;

}

signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cout << f();
}

