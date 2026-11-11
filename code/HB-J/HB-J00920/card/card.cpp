#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500007];
int jl[300007];
int have[300007];
stack <int> p;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++){
        for (int j = i;j <= n;j++){
            p.push(a[j]);
            if (jl[a[j]]) for (int k = jl[a[j]];k <= j;k++) jl[p.top()] = 0,p.pop();
            p.push(a[j]);
            jl[a[j]] = j;
        }
        for (int j = 1;j <= m;j++) if (jl[j]) have[j]++,jl[j] = 0;
        while (!p.empty()) p.pop();
    }
    for (int i = 1;i <= m;i++) cout << have[i] << ' ';
    return 0;
}
