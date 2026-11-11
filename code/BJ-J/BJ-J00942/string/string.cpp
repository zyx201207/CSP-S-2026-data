#include<bits/stdc++.h>
using namespace std;

long long n, a, cnt, ans;
char b, c[100000010];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin >> a >> b;
        for(long long j = 1; j <= a; j++){
            c[++cnt] = b;
        }
    }
    for(long long i = 1; i <= cnt / 2; i++){
        if(c[i] != c[cnt - i + 1]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}