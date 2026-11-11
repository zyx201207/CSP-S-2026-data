#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in", "r",stdin);
    freopen("string.out", "w",stdout);
    long long n, m, ans = 0;
    cin >> n;
    long long m1[n];
    char s[n];
    for(int i = 1; i <= n; i++){
        cin >> m1[i] >> s[i];
        m += m1[i];
    }
    char a[m];
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            a[i] = s[j];
        }
    }

    for(int i = 1; i <= m / 2; i++){
        for(int j = m; j > m / 2; j--){
            if(a[i] == a[j]) continue;
            else{
                ans++;
                a[i] = a[j];
            }
        }
    }

    cout << ans;
    return 0;
}

