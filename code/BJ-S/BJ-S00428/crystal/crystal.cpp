#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

long long mp[6000000];
long long pre[6000000];
long long n, m;
long long check(long long i, long long x){
    long long now = mp[i] * (i - x + 1);
    long long num = now - (pre[i] - pre[x - 1]);
    if (num <= m){
        return true;
    }
    else {
        return false;
    }
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld", &n);
    scanf("%lld", &m);
    for (int i = 1; i <= n; i++){
        long long k;
        scanf("%lld", &k);
        mp[i] = k;
    }
    sort(mp + 1, mp + 1 + n);
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + mp[i];
    }
    long long maxn = 0;
    for (int i = 1; i <= n; i++){
        long long ans;
        long long l = 1;
        long long r = i;
        while (l <= r){
            long long p = (r - l) / 2;
            long long mid = l + p;
            if (check(i, mid) == true){
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        maxn = max(i - ans + 1, maxn);
    }
    cout << maxn;
    return 0;
}
