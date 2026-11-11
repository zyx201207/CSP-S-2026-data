#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2 * 1e5 + 10;
int w[N];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        mx = max(mx, w[i]);
    }
    int cnt = 1;
    int mxi = 0;
    for(int i = 1; i <= mx; i++){
        if(w[i] != 0){
            cnt = (cnt & w[i]);
            mxi = max(mxi, cnt);
        }
    }
    cout << mxi;
    return 0;
}

