#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    unsigned long long n,m;
    cin >> n >> m;
    long long a[1000010];
    for(long long i = 1;i <= n; i++){
        cin >> a[i];
    }
    long long min_a = 1000000000001;
    long long under = 2;
    long long ans = 0;
    sort(a + 1, a + n + 1);
    for(long long i = 1;i <= m; i++){
        min_a = 1000000000001;
        for(long long j = 1;j <= n; j++){
            if(a[j] <= min_a){
                min_a = min(min_a, a[j]);
                under = j;
            }
        }
        a[under]++;
    }
    sort(a + 1, a + n + 1);
    long long max_ans = 0;
    bool is =true;
    for(long long i = 2;i <= n; i++){
        if(a[i] == a[i-1]){
            ans++;
            if(is){
                ans++;
                is = false;
            }
            max_ans = max(max_ans, ans);
        }
        else ans = 0;
    }
    cout << max_ans << "\n";
    return 0;
}
