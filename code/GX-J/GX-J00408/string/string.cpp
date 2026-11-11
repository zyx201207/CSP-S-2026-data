#include<bits/stdc++.h>
using namespace std;
long long n, ans;
long long a[200005];
char c[200005];
string s;
int main(){

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        cin >> c[i];
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= a[i]; j ++){
            s += c[i];
        }
    }
    for(int i = 0, j = s.size()-1; i <= s.size() / 2; i ++, j --){
        if(s[i] != s[j]){
            s[j] = s[i];
            ans ++;
        }
    }
    cout << ans;
    return 0;
}
