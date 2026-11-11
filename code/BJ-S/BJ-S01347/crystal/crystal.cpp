#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,a[500005],b[500005] = {},maxn = 1;
    unsigned long long m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i ++){
        b[i] = a[i] + b[i - 1];
    }
    int nn;
    nn = n + 1;
    while(nn --){
        for(int i = 0;i <= nn - maxn;i ++){
            if(b[nn] - b[i] + m >= (nn - i) * a[nn]){
                    maxn = max(maxn,nn - i);
                    if(nn - maxn <= 0){
                        cout << maxn;
                        return 0;
                }
                    break;
            }
        }
    }

    cout << maxn;
    return 0;
}
