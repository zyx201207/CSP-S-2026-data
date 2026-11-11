#include <bits/stdc++.h>
using namespace std;

long long n, m, maxn = 0, a[200005];
vector <long long> v[45];

long long getlg(long long n){
    long long mul = 1, res = 0;
    while (mul <= n){
        mul *= 2;
        res++;
    }
    return res - 1;
}

long long getb(long long n, long long k){
    return ((n >> k) & 1);
}

int main(){
    // printf("%d", getlg(15));
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for (long long i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        maxn = max(maxn, a[i]);
    }
    for (long long i = 1;i <= n; i++){
        v[getlg(maxn) + 1].push_back(a[i]);
    }
    for (long long i = getlg(maxn); i >= 0; i--){
        for (long long j = 0; j < v[i + 1].size(); j++){
            long long val = v[i + 1][j];
            if (val != 0 && getb(val, i) == 1){
                v[i].push_back(val);
            }
        }
        if (v[i].size() < m){
            v[i].clear();
            for (long long j = 0; j < v[i + 1].size(); j++){
                long long val = v[i + 1][j];
                v[i].push_back(val);
            }
        }
    }
    long long ans = v[0][0];
    //printf("%d ", v[0][0]);
    for (long long i = 1; i < v[0].size(); i++){
        ans &= v[0][i];
        //printf("%d ", v[0][i]);
    }
    //printf("\n");
    printf("%lld", ans);
    return 0;
}
