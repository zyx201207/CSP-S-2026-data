#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+1;
const int M = 3e5+1;
int a[N], f[M], s[M], v[M], cnt[M];
long long n, m;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
//    if (n * m >= (long long)(1e9)){
//        for (int i = 1; i <= m; i++) cout << n << " ";
//        return 0;
//    }
    for (int i = 1; i <= n; i += 1){
        f[i] = i;
        cin >> a[i];
        cnt[a[i]]+=1;
    }
    for (int i = n; i >= 1; i -= 1){
        if (v[a[i]]) continue;
        f[a[i]] = i;
        v[a[i]] = 1;
    }
    for (int i = 1; i <= m; i++) v[i] = 0;
    for (int i = 1; i <= n; i += 1){
        if (v[a[i]]) continue;
        v[a[i]] = 1;
        int j = i;
        while(j <= n){
            s[a[j]]+=cnt[a[i]];
            j = f[a[j]]+1;
        }
    }
    for (int i = 1; i <= m; i += 1) cout << s[i] << ' ';
    return 0;
}
