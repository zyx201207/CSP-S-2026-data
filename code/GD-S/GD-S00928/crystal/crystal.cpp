#include <bits/stdc++.h>
using namespace std;

long long find_max(long long* a, long long i){
    long long t = i + 1;
    while(a[t] <= a[i]) t++;
    return t;
}

long long a[1000000];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m; cin >> n >> m;
    for(long long i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    long long max_cnt = -1;

    for(long long i = find_max(a, 1); i <= n; i = find_max(a, i)){
        long long t = 1;
        while(t < i){
            while(a[t] < a[i]){
                if(m == 0){
                    sort(a + 1, a + n + 1);
                    long long cnt = 0;
                    long long j = 1;
                    while(j <= n){
                        cnt = find_max(a, j) - j;
                        max_cnt = max(max_cnt, cnt);
                        j = find_max(a, j);
                    }
                    cout << max_cnt << endl;
                    return 0;
                }
                a[t]++, m--;
            }
            t++;
        }
    }

    return 0;
}
