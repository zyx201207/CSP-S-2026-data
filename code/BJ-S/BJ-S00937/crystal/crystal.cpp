#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long sa1[500005], sa2[500005];
bool cmp(long long x, long long y){
    return x > y;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    a[0] = a[1];
    for(int i = 1;i <= n;i++){
        sa1[i] = sa1[i - 1] + a[i - 1] - a[i];
    }
    for(int i = 1;i <= n;i++){
        sa2[i] = sa2[i - 1] + sa1[i];
    }
    long long ans = 1;
    for(int i = 1;i <= n;i++){
        int l = i + 1, r = n;
        int save = 0;
        while(l < r){
            save++;
            if(save > 100000) break;
            int mid = (l + r + 1) / 2;
            long long num = sa2[mid] - sa2[i] - (mid - i) * sa1[i];
            if(m >= num)
                l = mid;
            else {
                r = mid - 1;
            }
            if(l == n && mid == n)
                break;
        }
        ans = max(ans, 1ll* l - 1ll*i + 1);
    }
    cout << ans << endl;
    return 0;
}
