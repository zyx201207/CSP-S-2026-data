#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long a[200005] = {};
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    long long c = 1 << n,maxn = -1;
    for(int i = 0;i < c;i++){
        if(__builtin_popcount(i) != m) continue;
        long long ans = (1 << 22) - 1;
        for(int j = 0;j < n;j++){
            if((i >> j) & 1){
                ans = ans & a[j + 1];
            }
        }
        maxn = max(maxn,ans);
    }
    cout << maxn;
    return 0;
}
