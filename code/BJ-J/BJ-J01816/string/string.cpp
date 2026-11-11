#include<bits/stdc++.h>
using namespace std;
int n;
long long t = 1, ans = 0;
long long s[200000005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        long long a;
        char c;
        cin >> a >> c;
        for(long long j = t; j < t + a; j++){
            s[j] = c - 'a' + 1;
        }
        t += a;
    }
    for(long long i = 1; i <= (t - 1) / 2; i++){
        if(s[i] != s[t - i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
