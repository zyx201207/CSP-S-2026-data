#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    static int sgn, res; sgn = 0, res = 0; static char ch = getchar();
    while(!isdigit(ch)) sgn ^= (ch == '-'), ch = getchar();
    while(isdigit(ch)) res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
    return sgn ? -res : res;
}

const int N = 2e5 + 10;
int n, ans, diff;

struct CH{
    int cnt;
    char c;
}a[N];

signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++){
        a[i].cnt = read();
        cin >> a[i].c;
    }
    int l = 1, r = n, sum = 0;
    while(l < r){
        while(sum + a[l].cnt <= a[r].cnt){
            sum += a[l].cnt;
            if(a[l].c != a[r].c) ans += a[l].cnt;
            l++;
        }
        if(a[l].c != a[r].c){
            ans += a[r].cnt - sum;
        }
        a[l].cnt -= a[r].cnt - sum;
        r--;
        sum = 0;
    }
    cout << ans;
    return 0;
}