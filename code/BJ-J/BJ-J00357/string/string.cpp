#include<bits/stdc++.h>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    
    int n, a[200005];
    long long qwq = 0, ans = 0;
    char c[200005];
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i] >> c[i];
        for(int j = 0; j < a[i]; j++){
            s += c[i];
        }
    }
    
    for(int i = 0, j = n - 1; i <= n / 2, j >= n / 2; i++, j--){
        if(s[i] != s[j]){
            ans++;
        }
    }
    
    cout << ans;
    
    return 0;
    
}