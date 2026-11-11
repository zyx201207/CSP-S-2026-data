#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(a) \
(freopen(#a".in", "r", stdin),\
freopen(#a".out", "w", stdout))
const int N = 2e5+5;
int c, T, n, m;
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    file(migrate);
    cin >> c >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        if(m / (a[2] - a[1]) == 2)
            cout << max(0, n-2) << '\n';
        else cout << "0\n";
    }
    return 0;
}
