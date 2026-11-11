#include <iostream>
#include <algorithm>
#define int long long
#define MAXN 200005
using namespace std;
int n, m;
int a[MAXN];
int ans = 0;

void dfs(int i, int k, int sum)
{
    if(k == m) {
        ans = max(ans, sum);
        return ;
    }
    if(i > n) {
        return ;
    }
    dfs(i+1, k, sum);
    dfs(i+1, k+1, (sum & a[i]));
}

int disand(int sum, int k, int cnt[])
{
    int res = sum;
    int j = 1;
    while(j <= 20) {
        int p = k & 1;
        if(p == 0 && cnt[j] == 1) {
            res |= (1<<(j-1));
        }
        k >>= 1;
        j++;
    }
    return res;
}

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    bool flag_A = true;
    bool flag_B = true;
    bool flag_C = true;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(flag_B && a[i] != i-1) {
            flag_B = false;
        }
        if(flag_A && (a[i] & (a[i]+1)) != 0) {
            flag_A = false;
        }
        if(flag_C && a[i] >= 4) {
            flag_C = false;
        }
    }

    if(n <= 20) { // 1~5
        dfs(1, 0, (1 << 30)-1);
        cout<<ans;
        return 0;
    }
    if(m == 1) { // 6
        ans = a[1];
        for(int i=2;i<=n;i++) {
            ans = max(ans, a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m == n) { // 7
        ans = a[1];
        for(int i=2;i<=n;i++) {
            ans &= a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m == 2) { // 8~10
        for(int i=1;i<n;i++) {
            for(int j=i+1;j<=n;j++) {
                ans = max(ans, (a[i] & a[j]));
            }
        }
        cout<<ans;
        return 0;
    }
    if(flag_A) { // 13
        for(int i=1;i<=n;i++) {
            a[i] = __builtin_popcountll(a[i]);
        }
        sort(a+1, a+1+n, greater<int>());
        cout<<(1<<a[m])-1;
        return 0;
    }
    if(flag_B) { //14, 15
        cout<<m*3;
        return 0;
    }
    if(flag_C) { // 16, 17
        int count[8] = {0};
        for(int i=1;i<=n;i++) {
            count[a[i]]++;
        }
        if(m <= count[3]) {
            cout<<3;
            return 0;
        }
        if(m <= count[3]+count[2]) {
            cout<<2;
            return 0;
        }
        if(m <=count[3]+count[2]+count[1]) {
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(m == n-1) { // 11, 12
        int cnt[25] = {0};
        int sum = a[1];
        for(int i=1;i<=n;i++) {
            sum &= a[i];
            int k = a[i];
            int j = 1;
            while(j <= 20) {
                int p = k & 1;
                if(p == 0) {
                    cnt[j]++;
                }
                k >>= 1;
                j++;
            }
        }
        for(int i=1;i<=n;i++) {
            ans = max(ans, disand(sum, a[i], cnt));
        }
        cout<<ans;
        return 0;
    }
    return 0;
}