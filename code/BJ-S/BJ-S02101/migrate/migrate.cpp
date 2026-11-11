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

const int N = 2e6 + 10;

int c,t,n,d,now,a[N],l1[N],r1[N],l2[N],r2[N],suml[N],sumr[N],ans;

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    c = read(),t = read();

    while(t--){
        now++;
        n = read(),d = read();
        ans = 0;
        for(int i = 0;i <= n + 1;i++){
            l1[i] = r1[i] = l2[i] = r2[i] = suml[i] = sumr[i] = 0;
        }
        for(int i = 1;i <= n;i++){
            a[i] = read();
        }
        int j = 1;
        for(int i = 1;i <= n;i++){
            while(a[i] - a[j] > d) j++;
            l1[i] = j;
        }
        l1[n + 1] = n + 1;
        j = n;
        for(int i = n;i >= 1;i--){
            while(a[j] - a[i] > d) j--;
            r2[i] = j;
        }
        r2[0] = 0;
        suml[0] = 1;
        for(int i = 1;i <= n;i++){
            r1[i] = l1[i + 1] - 1;
            l2[i] = r2[i - 1] + 1;
            suml[i] = suml[l1[i]] + r1[i] - l1[i] + 1;
            if(l1[i] > r1[i]) suml[i] = 1;
        }
        sumr[n + 1] = 1;
        for(int i = n;i >= 1;i--){
            sumr[i] = sumr[r2[i]] + r2[i] - l2[i] + 1;
            if(l2[i] > r2[i]) sumr[i] = 1;
        }
        j = 1;
        for(int i = 1;i <= n;){
            int r = i;
            while(r < n && r2[r + 1] == r2[i]) r++;
            while(j - r < 3 || (j <= n && l1[j] < r2[i] - 1)) j++;
            while(j <= n && l1[j] == r2[i] - 1){
                ans += (r - i + 1) * ((l1[j + 1] <= r2[i]) ? 1 : sumr[j]);
                if(r2[i - 1] < r2[i] - 1){
                    ans += (suml[i] - 1) * ((l1[j + 1] <= r2[i]) ? 1 : sumr[j]);
                }
                // ans += ((r2[i - 1] >= r2[i] - 1) ? 1 : suml[i]) * ((l1[j + 1] <= r2[i]) ? 1 : sumr[j]);
                // cout << i << " " << r << " " << j << " " << ans << endl;
                j++;
            }
            j--;
            i = r + 1;
        }
        cout << ans << endl;
        // for(int i = 1;i <= n;i++){
        //     cout << l1[i] << " " << r1[i] << " " << l2[i] << " " << r2[i] << " " << suml[i] << " " << sumr[i] << endl;
        // }
    }

    return 0;
}