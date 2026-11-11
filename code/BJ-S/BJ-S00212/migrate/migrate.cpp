#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 20;
int c, t, n, d, ans, x[maxn];
int dfs(int a, int b, int cnt, int now, int pos, long long ch){
    if(pos == b){
        if(now != cnt - 1) return 0;
        int last = a;
        ch |= (1 << b);
        for(int i = a; i <= b; i++){
            if(ch & (1 << i)){
                if(x[i] - x[last] > d) return 0;
                last = i;
            }
        }
        return 1;
    }
    else{
        long long sum = 0;
        if(pos != a && now != cnt - 1) sum += dfs(a, b, cnt, now + 1, pos + 1, ch | (1 << pos));
        sum += dfs(a, b, cnt, now, pos + 1, ch);
        return sum;
    }
}
int mind(int a, int b){
    if(x[b] - x[a] <= d) return 1;
    int pos = a, cnt = 0;
    int i = 1;
    while(pos < b){
        while(x[pos + i] - x[pos] <= d && pos + i <= n) i++;
        i--;
        if(i == 0) return 0;
        pos += i;
        cnt++;
    }
    return dfs(a, b, cnt, 0, a, 0);
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        ans = 0;
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
            cin >> x[i];
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                if(mind(i, j) == 2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
