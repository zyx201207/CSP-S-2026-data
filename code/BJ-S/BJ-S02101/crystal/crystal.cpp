#include <bits/stdc++.h>
using namespace std;
#define int long long

int read(){
    int k = 0,f = 1;
    char c = getchar_unlocked();
    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar_unlocked();
    }
    while('0' <= c && c <= '9'){
        k = k * 10 + c - '0';
        c = getchar_unlocked();
    }
    return k * f;
}

const int N = 5e5 + 10;

int n,m,a[N],sum[N],ans;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    n = read(),m = read();

    for(int i = 1;i <= n;i++){
        a[i] = read();
    }

    sort(a + 1,a + 1 + n);

    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + a[i];
    }

    for(int i = 1;i <= n;i++){
        int l = 1,r = i;
        while(l < r){
            int mid = (l + r) >> 1;
            if(a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        ans = max(ans,i - r + 1);
    }

    cout << ans << endl;

    return 0;
}