#include<bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 20;
long long n, m, ans = (1LL << 31) - 1, maxh = -1, rest, a[maxn], cnt[40];
bool flag[maxn];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
        for(long long j = 0; j <= 35; j++)
            if(a[i] & (1LL << j)) cnt[j]++;
    }
    for(long long i = 35; i >= 0; i--)
        if(cnt[i] >= m){
            maxh = i;
            rest = cnt[i];
            break;
        }
    if(maxh == -1){
        cout << 0 << endl;
        return 0;
    }
    for(long long i = 1; i <= n; i++)
        if(a[i] & (1LL << maxh)) flag[i] = true;
    for(long long i = maxh; i >= 0; i--){
        long long ch = 0;
        for(long long j = 1; j <= n; j++)
            if(flag[j] && a[j] & (1LL << i)) ch++;
        if(ch >= m){
            for(long long j = 1; j <= n; j++)
                if(flag[j] && !(a[j] & (1LL << i))) flag[j] = false;
            if(ch == m) break;
        }
    }
    for(long long i = 1; i <= n; i++){
        if(!flag[i]) continue;
        ans = (ans & a[i]);
    }
    cout << ans << endl;
    return 0;
}
