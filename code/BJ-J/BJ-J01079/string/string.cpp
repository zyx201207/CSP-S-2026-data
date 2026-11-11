#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s1,s2,s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int m = 0;
    for(int i = 1;i <= n;i++){
        int t;
        char r;
        cin >> t >> r;
        m += t;
        for(int j = 1;j <= t;j++) s.push_back(r);
    }
    int ans = 0;
    for(int i = m-1;i >= ceil(1.0 * (m - 1) / 2);i--){
        if(s[i] != s[m-1-i]) ans++;
    }
    cout << ans;
    return 0;
}
